
#include<bits/stdc++.h>
using namespace std ;


#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ll long long
#define ld long double
#define ar array
#define inf() ifstream cin("d.txt")
#define onf() ofstream cout("test.txt")
#define mod 1000000007
#define pb push_back
#define endl cout<<"\n";
#define prt1(a) cout<<a<<" "
#define prt2(a,b) cout<<a<<" "<<b<<" "
#define prt3(a,b,c) cout<<a<<" "<<b<<" "<<c<<" "
#define in(a) cin>>a
#define inn(a,b) cin>>a>>b
#define innn(a,b,c) cin>>a>>b>>c 
#define rep(i,st,end) for(int i=st;i<end;i++)
#define repv(i,st,end) for( i=st;i>=end;i--)
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define TEST ll tc;cin>>tc;while(tc--)
#define EACH(x, a) for (auto& x: a)

template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
    cin >> x;
}
void read(double& d) {
    string t;
    read(t);
    d=stod(t);
}
void read(long double& d) {
    string t;
    read(t);
    d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}
template<class A> void read(vt<A>& x) {
    EACH(a, x)
        read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
    EACH(a, x)
        read(a);
}
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a <<"\n";
    err(++it, args...);
}

// to find root  call using root(arr,element)

ll root (ll Arr[ ] ,ll i)
{
    while(Arr[ i ] != i)
    {
        Arr[ i ] = Arr[ Arr[ i ] ] ; 
i = Arr[ i ]; 
    }
return i;
}

  // to do union  initilize size[] by 1 
void weighted_union(ll Arr[ ],ll size[ ],ll A,ll B)
{
    ll root_A = root(Arr,A);
    ll root_B = root(Arr,B);
    if(size[root_A] < size[root_B ])
    {
Arr[ root_A ] = Arr[root_B];
size[root_B] += size[root_A];
}
    else
    {
Arr[ root_B ] = Arr[root_A];
size[root_A] += size[root_B];
}

}


void solve()
{
    ll n,m ;
    read(n,m);
    ll arr[n],size[n];
    rep(i,0,n)
    {
      arr[i] =  i;
      size[i] = 1;
    }
    rep(i,0,m)
    {
      ll x ,y ;
      read(x,y);
      --x;--y;
      if(root(arr,x)!=root(arr,y))
        weighted_union(arr,size,x,y);
    }
    map<ll,ll>mp;
    rep(i,0,n)
    mp[root(arr,i)]++;

    ll mx = 0;
    EACH(it,mp)
    mx=max(it.second ,mx);
    cout<<mx;
}

 int main()
 {
    fio;
    ll k = 1;
    ll tc = 1;
    // cin>>tc;
    while(tc--){
       // cout<<"Case #"<<k<<": ";k++;
        solve();
        endl;
    }
    
 }


