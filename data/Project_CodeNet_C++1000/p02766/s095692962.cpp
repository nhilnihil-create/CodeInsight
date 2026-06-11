#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int GetDigit(unsigned long long num,int d){

    return log(num) / log(d) + 1;
}

int main(){
    ll N;
    int K;
    cin >> N >> K;

    cout << GetDigit(N, K) << endl;

    return 0;
}
