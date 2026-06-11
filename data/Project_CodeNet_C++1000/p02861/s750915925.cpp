#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<double>v(n);
    rep(i,n)v[i] = i;
    vector<double>x(n),y(n);
    rep(i,n)cin >> x[i] >> y[i];
    double ans = 0;
    do{
        double sum = 0;
        rep(i,n-1)sum += sqrt(pow(x[v[i]]-x[v[i+1]],2) + pow(y[v[i]]-y[v[i+1]],2));
        ans += sum;
    }while(next_permutation(all(v)));
    double m = 1;
    rep(i,n)m *= i+1;
    cout << fixed << setprecision(10) << ans/m << endl;
    return 0;
}