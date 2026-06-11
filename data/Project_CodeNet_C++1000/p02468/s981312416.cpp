#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define show(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define show(x)
#endif

typedef long long int ll;
typedef pair<int,int> pii;
template<typename T> using vec=std::vector<T>;

const int inf=1<<30;
const long long int infll=1LL<<62;
const double eps=1e-9;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

ll power(ll x,ll y,ll mod){
	ll result=1;
	while(y>0){
		if(y&1) result=result*x%mod;
		x=x*x%mod;
        y>>=1;
	}
	return result;
}

void solve(){
    ll m,n;
    cin >> m >> n;
    cout << power(m,n,1e9+7) << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}