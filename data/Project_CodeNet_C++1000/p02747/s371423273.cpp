#include<bits/stdc++.h>
using namespace std;
bool debug;
#define all(x) (x).begin(), (x).end()
#define ll long long

#define db(x) if(debug)cout << " " << (x) <<" "
#define dbn(x) if(debug)cout << "\n" << (#x) << " is " << (x) << endl
#define endl "\n"
#define pb push_back
#define fi first
#define se second
#define rep(i,n) for(ll i=0;i<n;i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define per1(i,n) for(ll i=n;i>=1;i--)
// fill(all(vec), 1);
//vec.resize(unique(all(vec))-vec.begin())
const int N = 3e6;

void solve()
{
   string s;
   cin>>s;
   
   string a="hi",b="";
   while(b.size()<s.size())
   	b+=a;
   cout<<(s==b?"Yes":"No");

}



int main()
{
    debug = 0;


    if(debug)
    {
#ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
#endif
    }

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;


    while(t--)
    {
        solve();
        // cout << endl;
    }


}