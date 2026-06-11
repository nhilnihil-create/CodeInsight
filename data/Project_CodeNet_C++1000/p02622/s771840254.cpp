#include <bits/stdc++.h>
using namespace std;
/*  Writen by : AS7
 *  "JUST KEEP GOING..."
 */
#define endl			'\n'
#define ll				long long
#define all(v)			((v).begin()), ((v).end())
#define allr(v)			((v).rbegin()), ((v).rend())
#define sz(v)			((int)((v).size()))
#define clr(v, d)		memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define For(i,s)        for(auto i:s)
#define Forr(i,s)        for(auto &i:s)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define vi				vector <int>
#define vl				vector <ll>
#define ii				pair <int,int>
#define vii				vector <ii>
#define vll				vector <pair<ll,ll>>
#define PI				double PPPPPP = 3.14159265358979323846;
#define bit(mask,i) ((mask>>i)&1)
const int N = 2e5+5;
map<int ,bool> vis;
int ans;
void solve(){
   string s,t;
   cin>>s>>t;
   rep(i,s){
       ans+=(s[i]!=t[i]);
   }
   cout<<ans<<endl;
}
int main() {
    int t = 1;
   //cin>>t;
    while (t--)solve();
}