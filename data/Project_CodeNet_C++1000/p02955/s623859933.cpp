#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
using namespace std;
vector<long long> divisor(long long n){//nの約数列挙
    vector<long long> res;
    for(long long i = 1; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            if(i != n / i) res.push_back(n / i);
        }
    }
    return res;
}
long long gcd(long long x, long long y){
    if(x < y) swap(x, y);
    if( x % y == 0) return y;
    return gcd(y, x % y);
}
int main(){
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    long long sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    long long g = 0;
    for(int i = 1; i < N; i++){
        if(i == 1) g = gcd(A[i], A[i - 1]);
        else g = gcd(g, A[i]); 
    }
    vector<long long> div = divisor(sum);
    sort(div.begin(), div.end());
    for(int i = 0; i < (int)div.size(); i++){
        long long mosum = 0;
        vector<int> mo;
        if(div[i] > g){
            for(int j = 0; j < N; j++){
                if(A[j] % div[i] != 0) mo.push_back(A[j] % div[i]);
            }
            sort(mo.begin(), mo.end());
            int k = mo.size() - 1, h = 0;
            long long c = 0;
            while(k > h){
                c += mo[h];
                mosum += mo[h];
                h++;
                while(c > 0){
                    int res = min(c, div[i] - mo[k]);
                    c -= res;
                    mo[k] += res;
                    if(c > 0) k--;
                }
            }
            if(mosum <= K) g = div[i];
        }
    }
    cout << g << endl;
}