#include <bits/stdc++.h>
using namespace std;

vector<long long> divisor(long long n){
    vector<long long> ret;
    for(long long i = 1; i * i <= n; i++){
        if(n % i == 0){
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

void solve(long long N){
    //for(auto i : divisor(N)) cout << i << " ";
    //cout << endl;
    vector<long long> divisors = divisor(N);
    if(divisors.size() % 2 == 0) cout << divisors[divisors.size()/2-1] + divisors[divisors.size()/2] - 2 << endl;
    else cout << divisors[divisors.size()/2] * 2 - 2 << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}
