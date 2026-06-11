#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
int main(){
    ll t1,t2,a1,a2,b1,b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    a1=a1*t1;
    a2=a2*t2;
    b1=b1*t1;
    b2=b2*t2;
    a2+=a1;
    b2+=b1;
    if(a2==b2){
        cout << "infinity" << endl;
        return 0;
    }
    if(a2>b2){
        swap(a2,b2);
        swap(a1,b1);
    }
    if(b1>a1){
        cout << 0 << endl;
        return 0;
    }
    else if(b1<a1){
        ll c=a1-b1;
        ll d=b2-a2;
        if(c%d==0){
            cout << ((c+d-1)/d)*2 << endl;
        }
        else{
            cout << ((c+d-1)/d)*2 - 1 << endl;
        }
    }
    return 0;
}