#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e8;

const double pi = 3.141592653589793;

//---main---------------------------------------------
int main(){
    //main
    int A,B,H,M;
    cin >> A >> B >> H >> M;

    double theta, ans;
    theta = 2*pi*( (60*H+M)/720. - M/60.);

    ans = sqrt(A*A+B*B-2*A*B*cos(theta));
    
    printf("%.10f\n",ans);

    return 0;
}