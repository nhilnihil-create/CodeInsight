#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using ull = unsigned long long;
using P = pair<ll,ll>;
using grid = vector<vector<int>>;

const int dx[2] = {1, 0};
const int dy[2] = {0, 1};
const int INF = 1<<30;
const ll mod = 998244353LL;
const ull B = 1000000007;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ull pow(ull a, ull n) {
	ull ret = 1LL;
	for (; n > 0LL; n >>= 1LL, a = a * a) {
		if (n % 2LL == 1LL) {
			ret = ret * a;
		}
	}
	return ret;
}

int main() {
    ull N;
    string S;
    cin>>N>>S;
    int ans = 0;
    rep(i,N/2+1){
        if(i==0) continue;
        bool done = false;
        vector<ull> v(N-i+1,0);
        rep(j,N-i+1){
            if(j==0){
                rep(k,i){
                    ull s = S[k] - 'a';
                    v[j] = (v[j]*B+s);
                }
            }
            else {
                ull t = S[j-1]-'a', s = S[j+i-1]-'a';
                v[j] = (v[j-1]*B-pow(B,(ull)i)*t+s);
            }
        }
        map<ull,vector<ull>> m;
        rep(j,N-i+1){
            m[v[j]].push_back(j);
        }
        for(auto x:m){
            if(*x.second.rbegin()-*x.second.begin()>=i) {
                ans = i;
                done = true;
            }
        }
        if(!done) break;
    }
    cout<<ans<<endl;
}