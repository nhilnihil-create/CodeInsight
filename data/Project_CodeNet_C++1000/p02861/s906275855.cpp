#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

double kaijyo(int n){
    int k(1);
    for(int i=n;i>0;i--){
        k *= i;
    }

    return k;
}

double distance(int x[],int y[],int i,int j){
    int dx = (x[i] - x[j]) * (x[i] - x[j]);
    int dy = (y[i] - y[j]) * (y[i] - y[j]);
    return sqrt(dx+dy);
}

int main(){
    int n;  cin >> n;
    int x[n],y[n];
    rep(i,n)    cin >> x[i] >> y[i];

    double d[n][n];
    rep(i,n){
        rep(j,n){
            d[i][j] = distance(x,y,i,j);
        }
    }

    vector<int> next(n);
    rep(i, n) next[i] = i;

    double sum(0.0);

    do{
        rep(i,n-1){
            sum += d[next[i]][next[i+1]];
        }
    } while (next_permutation(next.begin(), next.end()));

    sum /= kaijyo(n);

    cout << setprecision(10) << sum << endl;

    return 0;
}