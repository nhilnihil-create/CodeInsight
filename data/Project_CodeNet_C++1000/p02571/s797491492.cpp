#include<bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int               long long
#define endl              "\n"
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define ff                first
#define ss                second
#define pii               pair<int,int>
#define vi                vector<int>
#define vpi               vector<pair<int,int>>
#define mii               map<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define repe(i,a,b)        for(int i=a;i<=b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define INF 100000000000
#define mod 1000000007
#define esp 10e-7
const int mx=100001;

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //freopen("error.txt" , "w" , stderr);
    #endif
    IOS
    string s,t;
    cin>>s;
    cin>>t;
    // cout<<s<<t<<endl;
    int n=s.length();
    int k=t.length();
    vector<string>v;
    int i=0,j=k-1;
    string temp;
    while(i<=(n-k))
    {
      temp=s.substr(i,k);
      v.pb(temp);
      i++;
    }
    int ans=INT_MAX;
    for(int i=0;i<v.size();i++)
      { int cnt=0;
        for(int j=0;j<k;j++)
            if(v[i][j]!=t[j])
                cnt++;
            ans=min(cnt,ans);
      }
      cout<<ans<<endl;
    return 0;
}
