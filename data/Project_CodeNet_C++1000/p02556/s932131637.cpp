  #include<bits/stdc++.h>
  using namespace std;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define ll  long long
  #define ld long double
  #define pb push_back
  #define mp3 make_pair
  #define rep1(i,a,b) for(ll i=a;i<=b;i++)
  #define rep2(i,a,b) for(ll i=a;i<b;i++)
  int main(){
    IOS;
    ll n;
    cin>>n;
    ll a[n],b[n];
    vector<ll> p,q;
    for(ll i=0;i<n;i++){
      cin>>a[i]>>b[i];
     p.pb(a[i]+b[i]);
     q.pb(a[i]-b[i]);
    }
  sort(p.begin(),p.end());
  sort(q.begin(),q.end());
  cout<<max(p[n-1]-p[0],q[n-1]-q[0])<<endl;
  }