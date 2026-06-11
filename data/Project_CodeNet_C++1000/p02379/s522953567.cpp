#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(v) v.begin(), v.end()
#define PI 3.141592653589793238462643383279
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;
const long long MOD = 1e9+7;
const ll INF = 1LL << 60;

int main(){

    double x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double a = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    printf("%.8lf",a);

}
