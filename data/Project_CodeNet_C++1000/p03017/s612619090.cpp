#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)   
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

int main(){
    
    ll n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s;

    a--;b--;c--;d--;
    rep(i,a,c-1){
        if(s[i] == '#' && s[i+1] == '#'){
            cout << "No" << endl;
            return 0;
        }
    }
    rep(i,b,d-1){
        if(s[i] == '#' && s[i+1] == '#'){
            cout << "No" << endl;
            return 0;
        }
    }

    if(b < c && c < d){
        cout << "Yes" << endl;
        return 0;
    }
    else if(c < d){
        cout << "Yes" << endl;
        return 0;
    }

    rep(i,b-1,d){
        rep(j,0,3){
            if(s[i+j] == '#') break;
            else if(j == 2){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}