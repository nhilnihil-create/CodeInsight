#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
typedef vector<vector<int> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const double INF = 1e9;

//input
ll t1,t2;
ll a1,a2;
ll b1,b2;

ll move_forward,move_back;


void input(){
    cin >> t1 >> t2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;
}

void initial(){
    if(a1<b1){
        swap(a1,b1);
        swap(a2,b2);
    }
    move_forward = (a1-b1)*t1;
    move_back = (a2-b2)*t2;
}

bool inf_check(){
    if(move_forward+move_back==0)return true;
    return false;
}

bool non_check(){
    if(move_forward+move_back>0)return true;
    return false;
}

ll solve(){
    ll x = move_forward;
    ll dif = abs(move_forward+move_back);
    ll res = 0;
    res += x/dif*2+1;
    if(x%dif==0)res--;
    return res;
}

int main(){
    input();
    initial();
    if(inf_check()){
        cout << "infinity" << endl;
        return 0;
    }
    if(non_check()){
        cout << 0 << endl;
        return 0;
    }
    cout << solve() << endl;
    return 0;
}

