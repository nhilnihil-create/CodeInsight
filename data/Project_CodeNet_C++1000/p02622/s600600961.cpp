/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠺⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⠀⠈⢿⣦⣄⣈⣁⣀⣠⣴⣦⡀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣠⣶⣿⣿⣿⣿⣿⣿⣶⡄⠙⢿⣿⣿⣿⣿⣿⡿⠓⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠙⣿⣿⠿⠛⠛⠛⠛⣿⣿⡄⠀⠈⠉⠉⠉⣁⣀⡀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⣸⣿⡇⠀⠀⠀⣴⣿⣿⡿⠿⢷⣄⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠠⣤⣤⣴⣾⣿⡿⠁⠀⢀⣾⣿⣿⠏⠀⠀⠈⣿⣧⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣏⠀⠀⣠⣾⣿⣿⠏⠀⠀⠀⠀⢹⣿⡄⠀⠀
⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠻⣿⣿⡟⠻⠿⠛⠁⠀⠀⠀⠀⠀⣾⣿⡇⠀⠀
⠀⠀⠘⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⡄⠀⣄⠀⠀⠀⠀⠀⣰⣿⣿⠇⠀⠀
⠀⠀⠀⢿⡄⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⠇⠀⠹⣷⣤⣤⣤⣾⣿⣿⡟⠀⠀⠀
⠀⠀⠀⠈⢿⣦⣄⣀⠀⠀⣀⣠⣾⣿⣿⡟⠀⠀⠀⠘⠻⣿⣿⣿⠿⠋⠀⠀⠀⠀
⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⣿⣿⣿⡿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠉⠙⠛⠛⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀

           KRISHNA ASHOK⠀
*/

#include <bits/stdc++.h>
using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds; 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Tree;
// order_of_key(k), find_by_order(k)


#define dbg(x) cout<<#x<<"="<<x<<'\n'
#define ll long long
#define pr pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define For(i,n) for(int i=0;i<(n);++i)
#define Forr(i,n) for(int i=n-1;i>=0;i--)
#pragma GCC optimization("Ofast")
#pragma GCC optimization("unroll-loops")
#define fin ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
#define sz(a) (int)a.size()
#define Fill(a,b) memset(a,b,sizeof(a));
#define fileio freopen("http://in.in", "r", stdin),freopen("out.out", "w", stdout);
const int INF=1e9;
//#define endl '\n'
#define fit(i,x) for(auto i:x)
#define gcd(a,b) __gcd(a,b)
#define Max(a,b) a=max(a,b)
#define Min(a,b) a=min(a,b)
#define vt vector
#define ppr pair<int,pair<int,int>>



void solve(){
	string s,t;
	cin>>s>>t;
	int ans=0;
	for(int i=0;i<sz(s);i++){
		if(s[i]!=t[i])ans++;
	}
	cout<<ans<<endl;
}



int main()
{
    fin;
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}