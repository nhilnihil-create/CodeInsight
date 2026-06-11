#include<bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("03")
#define ll long long
#define pb push_back
#define nl '\n'
#define popb pop_back()
#define sz size()
#define inf 1000000000
#define ld long double
#define ull unsigned long long
#define F first
#define S second
#define fix fixed<<setprecision
#define pii pair<int,int>
#define E exit(0)
ll dp[2001];
int main() {
    //freopen("tshirts.in", "r", stdin);
	//freopen("tshirts.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int s;
	cin>>s;
	dp[0]=1;
    for (int i=1;i<=s;i++) {
        for (int j=3;i-j>=0;j++) {
            dp[i]+=dp[i-j];
        }
        dp[i]%=(inf+7);
    }
    cout<<dp[s]%(inf+7);
}