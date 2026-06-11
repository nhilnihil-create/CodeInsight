#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<long long> divisor(long long n){//nの約数列挙
    vector<long long> res;
    for(long long i = 1; i * i <= n; i++){
        if(n % i == 0){
            if(i != 1) res.push_back(i);
            if(i != n / i) res.push_back(n / i);
        }
    }
    return res;
}


long long gcd(long long x, long long y){
    if(x < y) swap(x, y);
    if(x % y == 0) return y;
    return gcd(y, x % y);
}
int main(){
    long long N;
    cin >> N;
    long long cnt = 0;
    if(N == 1){
        cout << 1 << endl;
        return 0;
    }
    vector<long long> sisuu = divisor(N);
    for(int i = 0; i < (int) sisuu.size(); i++){
        long long n = N;
        while(n > 1){
            if(n % sisuu[i] == 0) {
                n/= sisuu[i];
                if(n == 1) cnt++;
            }
            else{
                if(n % sisuu[i] == 1) cnt++;
                break;
            }
        }
    }
    vector<long long> yak = divisor(N - 1);
    cnt += yak.size();
    cout << cnt << endl;
}