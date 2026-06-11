#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];
    int array[]={0,1,2,3,4,5,6,7};
    double sum = 0;
    do{
        for(int i=0; i<n-1; i++){
            auto ix = array[i];
            auto iy = array[i+1];
            double dx = x[ix] - x[iy];
            double dy = y[ix] - y[iy];
            sum += sqrt(dx * dx + dy * dy);
        }
    }while(next_permutation(array,array+n));
    double div = 1;
    rep(i, 1, n+1) div *= (i);
    cerr << div << endl;
    printf("%.10lf\n", sum/div);
    return 0;
}