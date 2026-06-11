#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define debug(x) cout << "debug" << x << endl;
using namespace std;

double P(double x, double y, int p){
    double dis = abs(x - y);
    double ans = dis;
    rep(i,p - 1) ans *= dis;
    return ans;
}

double sum(double x[128], double y[128], int p, int n){
    double ans = 0;
    rep(i,n){
        ans += P(x[i],y[i],p);
    }
    return pow(ans, 1.0 / p);
}

int main(){
    int n;
    while(cin >> n){
        double x[128], y[128];
        double maxNum = 0;
        rep(i,n) cin >> x[i];
        rep(i,n) cin >> y[i];
        rep(i,3) printf("%.6lf\n",sum(x,y,i+1,n));
        rep(i,n){
            double num = P(x[i],y[i],1);
            if(num >= maxNum) maxNum = num;
        }
        printf("%.6lf\n",maxNum);
    }
}