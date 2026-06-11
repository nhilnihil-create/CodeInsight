#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;


void warshall_floyd(int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

int main() {
//    long double w,h,x,y; cin >> w >> h >> x >> y;
//    long double vertical = h * x;
//    long double side = w * y;
//
//    if(vertical > side ){
//        cout << fixed << setprecision(9) << side << " " << 0 << endl;
//    }else if(vertical < side){
//        cout << fixed << setprecision(9) << vertical << " " << 0 << endl;
//    }else{
//        cout << fixed << setprecision(9) << vertical << " " << 1 << endl;
//    }
    long long W, H, x, y;
    cin >> W >> H >> x >> y;
    double res = (double)(W) * H / 2;
    cout << fixed << setprecision(10) << res << " ";

    if (x*2 == W && y * 2 == H) cout << 1 << endl;
    else cout << 0 << endl;
    
 }

