#include <iostream>
#include <vector>
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
int main(){
    long long N;
    cin >> N;
    vector<long long> d = divisor(N);
    long long ans = 1e18;
    for(int i = 0; i < d.size(); i++){
        long long t = d[i];
        long long temp = (t - 1) + N / t - 1;
        if(temp < ans) ans = temp;
    }
    cout << ans << endl;
}