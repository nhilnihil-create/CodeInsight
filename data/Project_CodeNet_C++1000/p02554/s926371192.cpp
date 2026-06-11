// Best practice
 
#include<bits/stdc++.h>
 
#define int         long long
#define pb          push_back
#define pf          emplace_front
#define all(a)      (a).begin(),(a).end()
#define rall(a)     (a).rbegin(),(a).rend()
#define pii 		pair<int,int>
#define psi 		pair<string,int>
#define vi 			vector<int>
#define vpii  		vector<pii>
#define vvi 		vector<vi>
#define sz(x)	    (int)(x).size()
#define x           first
#define y           second
#define endl        '\n'
#define tezz        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD         1000000007
#define hell        998244353
#define prec(n) 	fixed<<setprecision(n)
#define ini(a, i) 	memset(a, i, sizeof(a))
#define output(x)   cout << (x ? "YES" : "NO")<<endl;
using namespace std;
 
#define debug(vec) cout<<(#vec)<<" : [ "; for (auto& i: vec) cout<<i<<" "; cout<< "]" << endl
#define debugp(vec) cout<<(#vec)<<" : [ "; for (auto& i: vec) cout<<"("<<i.x<<","<<i.y<<")"<<" "; cout<< "]" << endl
#define trace(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args);cout << endl; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << "[" << *it << ": " << a << "]\t";
    err(++it, args...);
}
 
// const int dx[4] = { -1, 1, 0, 0};
// const int dy[4] = {0, 0, -1, 1};
// int dX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
// int dY[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
 
 
// Code from Here -------------------------------------------------------------------------------

int poww(int a, int b){
    a%=MOD;
    int res=1;
    while(b>0){
        if(b&1)res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

int ncr(int n,int r){
    if(r>n-r)r=n-r;
    int ans=1;
    for(int i=1;i<=r;i++){
        ans=((ans*(n-i+1)%MOD)*poww(i,MOD-2))%MOD;
    }
    return ans;
}

int sub_mod(int a, int b) {
    a %= MOD, b %= MOD;
    a -= b;
    if (a < 0)a += MOD;
    return a;
}

int add_mod(int a, int b) {
    a %= MOD, b %= MOD;
    return (a + b) % MOD;
}

int mul_mod(int a, int b) {
    a %= MOD, b %= MOD;
    return (a * b) % MOD;
}

int div_mod(int a, int b) {
    a %= MOD, b %= MOD;
    return mul_mod(a , poww(b, MOD - 2));
}

const int nax = 1e6+5;
int pow8[nax], pow2[nax];

signed main() {
	tezz
 

	int n;
	cin >> n;
	pow8[0] = pow2[0] = 1;
	for(int i=1; i<=n; i++){
		pow8[i] = (pow8[i-1] * 8)%MOD;
		pow2[i] = (pow2[i-1] * 2)%MOD;
	}
	if(n==1){
		cout << 0 << endl;
	}
	else{
		int ans = 0, ncr=n;
		for(int i=2; i<=n; i++){
			ncr = mul_mod(ncr, n-i+1);
			ncr = div_mod(ncr, i);
			ans = add_mod(ans, mul_mod(ncr, mul_mod(pow8[n-i], sub_mod(pow2[i], 2))));
		}
		cout << ans << endl;
	}
 
	return 0;
}  