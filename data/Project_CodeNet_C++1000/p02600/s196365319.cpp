#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N; i >= 0; i--)
const ll INF = 1000000000000000000;
//input
int X;


//processing



//dpTable
//int dp[100050];

int main(){
    cin >> X;
    if (X >= 400 && X <= 599) cout << 8 << endl;
    if (X >= 600 && X <= 799) cout << 7 << endl;
    if (X >= 800 && X <= 999) cout << 6 << endl;
    if (X >= 1000 && X <= 1199) cout << 5 << endl;
    if (X >= 1200 && X <= 1399) cout << 4 << endl;
    if (X >= 1400 && X <= 1599) cout << 3 << endl;
    if (X >= 1600 && X <= 1799) cout << 2 << endl;
    if (X >= 1800 && X <= 1999) cout << 1 << endl;
    return 0;
}