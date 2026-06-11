#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N; i >= 0; i--)
const ll INF = 1000000000000000000;
//input
int A,B,C,K;


//processing
int cnt;


//dpTable
//int dp[100050];

int main(){
    cin >> A >> B >> C >> K;
    while (A >= B){
        cnt++;
        B *= 2;
    }
    while (B >= C){
        cnt++;
        C *= 2;
    }
    if (cnt <= K) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}