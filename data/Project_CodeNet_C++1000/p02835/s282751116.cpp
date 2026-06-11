
// Problem: A - Blackjack
// Contest: AtCoder - AtCoder Beginner Contest 147
// URL: https://atcoder.jp/contests/abc147/tasks/abc147_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define ll long long
const int N = 2e5+5;
const int mod = 1e9;
#define ld long double
#define PI 3.14159265358979323846
#pragma GCC optimize("-O2")
const int INF = 10000000;
 
void flash()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(9);
}
 
//3. Structure or classes
//3. Ends here
 
//1. Data structures declaration here
//1. Ends here
 
//2. Extra Functions here
//2. Ends here
 
 
void solve();
int32_t main()
{
    flash();
    int t;
    t = 1;
    //cin>>t;
    while(t--){
        solve();
        //cout<<"\n";
    }
    return 0;
}
 
 
 
void solve()
{
	int a1,a2,a3;
	cin>>a1>>a2>>a3;
	if(a1+a2+a3>=22){
		cout<<"bust\n";
	}
	else cout<<"win\n";
    return;
}
// how r u bro