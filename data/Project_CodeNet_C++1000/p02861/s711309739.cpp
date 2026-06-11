#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];
    int array[n];
    rep(i, 0, n) array[i] = i;
    double sum = 0;
    do{
        for(int i=0; i<n-1; i++){
            ll nxt = array[i+1];
            ll cur = array[i];
            double dx = x[nxt] - x[cur];
            double dy = y[nxt] - y[cur];
            sum += sqrt(dx * dx + dy * dy);
        }
    }while(next_permutation(array,array+n));
    double div = 1;
    rep(i, 1, n+1) div *= i;
    printf("%.20lf\n", sum/div);
    return 0;
}