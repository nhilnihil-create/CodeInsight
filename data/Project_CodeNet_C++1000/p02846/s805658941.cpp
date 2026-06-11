#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
//小数点以下　cout << fixed << setprecision(10) << num << endl;
//桁数はlog10(mid)でやれ　log(mid)/log(10)はWA

int main(){
    ll t1,t2; cin >> t1 >> t2;
    ll a1,a2,b1,b2;
    cin >> a1 >> a2 >> b1 >> b2;
    ll one=(a1-b1)*t1;
    ll two=(a2-b2)*t2;
    ll a=two+one;
    if(a==0){
        cout << "infinity" << endl;
        return 0;
    }
    if(one>0&&a>0){
        cout << 0 << endl;
        return 0;
    }
    if(one<0&&a<0){
        cout << 0 << endl;
        return 0;
    }
    if(one<0) one*=-1;
    if(a<0) a*=-1;
    if(one%a!=0) cout << 2*(one/a)+1;
    else cout << 2*(one/a);
}
