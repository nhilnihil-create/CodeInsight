   #include<bits/stdc++.h>
    using namespace std;

    #define ll long long
    #define ff first
    #define ss second
    #define pb push_back
    #define vll vector<ll>
    #define mll map<ll,ll>
    #define MOD 1000000007
    #define pll pair<ll,ll>
constexpr ll INF = 1999999999999999997; 
    #define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
    int main() {
      fastio;

      int n;
      cin>>n;
      vector<pll>v;
      for(int i=0;i<n;i++)
      {
        ll a;
        cin>>a;
        v.pb({a,i+1});
      }
      sort(v.begin(),v.end());
      int c=0;
      int x=1;
      int pos=-1;
      for(auto j:v)
      {  //cout<<j.ff<<' '<<j.ss<<endl;
        if(j.ff==x)
        {
          if(j.ss>pos)
         { x++;
          c++;
          pos=j.ss;
        }
        }
      }
      if(c==0)
        cout<<-1<<endl;
      else
        cout<<n-c<<endl;
    }