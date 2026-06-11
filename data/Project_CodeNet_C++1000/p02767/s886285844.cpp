    #include<bits/stdc++.h>
  using namespace std;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define endl "\n"
  #define ll long long
  #define int long long
  #define double long double
  #define max(a,b) (a>b?a:b)
  #define min(a,b) (a<b?a:b)
  #define mp make_pair
  #define pb push_back
  #define inf INT_MAX
  #define f first
  #define s second
  #define trace1(x)                cerr<<#x<<": "<<x<<endl
  #define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
  #define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
  #define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
  #define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<< ": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
  #define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
  #define cases int testcases;cin>>testcases; while(testcases--)
  #define all(v) v.begin(), v.end()
  #define mod INT_MAX 
  const int MOD=1e9+7;
  const int N=2e5+2;

  int32_t main()
  {
    #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);
    #endif
       IOS
       //Rally C atcoder
       int n,x,l=INT_MAX,r=0;
       cin>>n;
       vector<int> v(n);
       for(int i = 0;i<n;i++)
       {
        cin>>v[i];
        l = min(l,v[i]);
        r = max(r,v[i]);
       }
       int ans = INT_MAX;
       for(int i = l;i<=r;i++)
       {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=(v[j]-i)*(v[j]-i);
            }
            ans=min(ans,sum);
       }
       cout<<ans;
       return 0;
    }