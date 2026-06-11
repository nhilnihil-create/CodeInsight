#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    int n=0;
    cin >> n;
    int x[n],y[n];
    rep(i,n)cin >> x[i] >> y[i];
    int cur[n];
    rep(i,n)cur[i]=i;
    long double dict=0.0,sum=0.0;
    do{
        rep(i,n-1){
            long double a = pow((double)x[cur[i]]-(double)x[cur[i+1]],2);
            long double b = pow((double)y[cur[i]]-(double)y[cur[i+1]],2);
            dict += pow(a+b,0.5);
        }
        sum+=dict;
        dict = 0;
    }while(next_permutation(cur,cur+n));

    int factorial = 1;
    rep2(i,2,n+1)factorial*=i;
    cout << fixed << setprecision(10) << sum / factorial << endl;

    return 0;
}