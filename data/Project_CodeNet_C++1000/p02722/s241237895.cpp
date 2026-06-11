#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cout<<#var<<"="<<var<<endl;
#define dup(x,y) (((x)+(y)-1)/(y))
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
const int INTMAX = 2147483647;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    ll n;cin >> n;
    int count = 1;
    for(ll k=2;k*k<=n-1;++k){
        if((n-1)%k==0){
            ++count;
            if((n-1)/k!=k) ++count;
            cerr << "err1 " << k << endl;
        }
    }

    for(ll k=2;k*k<=n;++k){
        if(n%k==0){
            ll m = n;
            while(m%k==0 && m!=0) m /= k;
            cerr << k << " " << m << endl;
            if(m%k==1){
                cerr << "err2 " << k << endl;
                ++count;
            }
        }
    }
    if(n%(n-1)==1) ++count;
    cout << count << endl;
}