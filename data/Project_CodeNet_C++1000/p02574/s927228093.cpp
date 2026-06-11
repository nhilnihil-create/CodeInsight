#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const ll INF = 1001001001;
const ll LINF = 1001001001001001001;

void prvec(vector<ll> vec){
    ll n = vec.size();
    rep(i,n) cout << i << " " << vec.at(i) << "\n";
}

void pr2d(vector<vector<ll>> vvec){
    ll h = vvec.size();
    ll w = vvec.at(0).size();
    rep(i,h){
        rep(j,w){
            cout << vvec.at(i).at(j) << " ";
        }
        cout << "\n";
    }
}

int main(){
    ll n ;
    cin >> n;
    vector<ll> a(1000001,1);
    a.at(0) = 0;
    a.at(1) = 0;
    for(int i=2;i<=1000;i++){
        if(!a.at(i)) continue;
        ll x = i;
        while(true){
            x+=i;
            if(x>1e6) break;
          	a.at(x) = 0;
        }
    }

    vector<ll> b(1000001,0);
    rep(i,n){
        ll x; cin >> x;
        b.at(x)++;
    }
    bool pairwise = 1;
    bool setwise = 1;

    rep(i,1000001){
        if(!a.at(i)) continue;
        ll cnt = 0;
        ll x = i;
        while(x<=1e6){
            if(b.at(x)) cnt+=b.at(x);
            x+=i;
        }
        if(cnt>1) pairwise = 0;
        if(cnt==n){
            pairwise = 0, setwise = 0;
            break;
        }
        //cout << i << " " << cnt << endl;
    }
  	//cout << setwise << endl;
    if(pairwise){
        cout << "pairwise coprime" << endl;
    }else if(setwise){
        cout << "setwise coprime" << endl;
    }else{
        cout << "not coprime" << endl;
    }
    return 0;
}