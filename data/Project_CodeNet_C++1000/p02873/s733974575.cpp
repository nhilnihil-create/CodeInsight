#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define pll pair<ll,ll>
#define pb push_back
#define F first
#define S second
#define I insert
#define vll vector<ll>
#define vbl vector<bool>
#define vvll vector<vll>
#define vld vector<ld>
#define vb vector<bool>
#define vc vector<char>
#define vpll vector<pll>
#define all(x) (x).begin(), (x).end()

template<class T> ostream& operator<<(ostream &os, vector<T> V){
	os << "[ ";
	for(auto v  : V) os << v << " ";
	return os << " ]";
}
template<class T> ostream& operator<<(ostream &os, set<T> V){
	os << "[ ";
	for(auto v  : V) os << v << " ";
	return os << " ]";
}
template<class T , class R > ostream& operator<<(ostream &os, map<T , R> V){
	os << "[ ";
	for(auto v  : V) os << "(" << v.first << ":" << v.second << ")";
	return os << " ]";
}
template<class T , class R > ostream& operator<<(ostream &os, pair<T , R> V){
	return os << "(" << V.first << "," << V.second << ")";
}

#define cerr cout
#define TRACE
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }
    clock_t clk=clock();
    #define checktime() cout<<"\nTime Elapsed : "<<float(clock()-clk)/CLOCKS_PER_SEC<<endl
#else
    #define trace(...);
    #define checktime();
#endif

const ll Mod = 1e9 + 7;
// const ll Mod = 998244353;
const ll MAXN = 1e6;

void solve(){
    // 0<3>2>1>0<1<2>0<1<2<3<4<5>2>1>0<1

    string s;cin>>s;
    ll n=s.size();
    ll sum=0,val=0,lt=0;
    vll a={0},b(n+1,0);
    vpll v={{0,0}};
    for(ll i=0;i<n;i++){
        if(s[i]=='<'){
            lt=0;
            val++;
            sum+=val;
        }else{
            if(lt==0){
                val=0;
                lt++;
                a.pb(val);
                v.pb({val,sum});
                continue;
            }
            lt++;
            val--;
            if(val<0){
                // trace(i-lt+2,i);
                b[i-lt+2]++;b[i+1]--;
                val=0;
                sum+=lt-1;
            }else{
                sum+=val;
            }
        }
        a.pb(val);
        // v.pb({val,s2um});
        // trace(i,sum);
    }
    for(ll i=1;i<n+1;i++) b[i]+=b[i-1];
    // trace(b);
    for(ll i=0;i<n+1;i++) a[i]+=b[i];
    // trace(a);
    for(ll i=0;i<n;i++) if(s[i]=='>'&&a[i]<=a[i+1]) a[i]=a[i+1]+1;
    // trace(a);
    // trace(v);
    sum=0;
    for(ll i=0;i<n+1;i++) sum+=a[i];
    cout<<sum<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout<<fixed<<setprecision(25);

    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}