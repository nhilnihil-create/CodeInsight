#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    double A, B, X; cin >> A >> B >> X;
    double volume = A * A * B;
    if(X < volume / 2){//角度は鈍角
        double theta = atan(2*X / (A*B*B));
        theta = theta *180.0 /M_PI;
        cout << fixed << setprecision(10) << 90.0 - theta << endl;
    }else{//こっちは鋭角
        double x_dash = volume - X;
        double theta = atan(2*x_dash /(A*A*A));
        theta = theta*180/M_PI;
        cout <<fixed << setprecision(10) << theta << endl;
    }
}
