#include <bits/stdc++.h>
using namespace std;
const auto start_time = std::chrono::high_resolution_clock::now();
void timecalculater(){
    #ifndef ONLINE_JUDGE
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
    #endif
}
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repA(i, a, n) for(int  i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
#define fill(a,v) memset(a, v, sizeof(a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long int> vll;
typedef vector<pii> vii;
ll p=1e9+7;
const int N=2e5+5;
int main() {
    
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int T=1;
    // cin>>T;
    while(T--){
        int n,k,c;cin>>n>>k>>c;
        string s;cin>>s;
        int pre[n]={0},suf[n]={0};
        vector<int> v;
        int last=-2*n;
        vector<int> ans;
        for(int i=0;i<n;i++){
        	if(s[i]=='o'){
        		if((i-last)>c){
        			v.pb(i);
        			last=i;
        		}
        	}
        }
        if(s[0]=='o')pre[0]=1;
        for(int i=1;i<n;i++){
        	if(s[i]=='x'){
        		pre[i]=pre[i-1];
        	}
        	else{
        		if(i-c-1>=0)
        		pre[i]=pre[i-c-1]+1;
        		else
        		pre[i]=1;
        	}
        }
        if(s[n-1]=='o')suf[n-1]=1;
        for(int i=n-2;i>=0;i--){
        	if(s[i]=='x'){
        		suf[i]=suf[i+1];
        	}
        	else{
        		if(i+c+1<n)
        		suf[i]=suf[i+c+1]+1;
        		else
        		suf[i]=1;
        	}
        }
        for(auto j:v){
        	int u=c;
        	int i=j-1;
        	int f=1;
        	int x=0,y=0;
        	if(i>=0){
        		x=pre[i];
        	}
        	if((j+1)<n){
        		y=suf[j+1];
        	}
        	if(x+y>=k){
        		f=0;
        	}
        	while(u--){
        		int ii=i+c+1;
        		int x=0,y=0;
        		if(i>=0)x=pre[i];
        		if(ii<n)y=suf[ii];
        		if(x+y>=k){
        			f=0;break;
        		}
        		i--;
        	}
        	if(f){
        		ans.pb(j);
        	}
        }
        for(auto j:ans){
        	cout<<j+1<<endl;
        }
    }   
    timecalculater();
    return 0;   
} 