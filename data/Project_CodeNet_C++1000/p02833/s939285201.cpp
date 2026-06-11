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

      ll n;
      cin>>n;
      ll count=0;
      //int i=1;
      if(n&1)
        cout<<0<<endl;
      else
      {
      n=n/2;
      while(n)
      {  count+=n/5;
        n=n/5;
      }
      cout<<count<<endl;
    }
    }