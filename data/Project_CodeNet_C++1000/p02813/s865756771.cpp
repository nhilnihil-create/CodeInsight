#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; i++)
static const long long INF = 1000000;
using p = pair<int,int>;
struct trio{
    int first;
    int second;
    int third;
};
int main(){
    int n;
    cin >> n;
    vector<int> norm(n);
    rep(i,n){
        norm[i] = i + 1;
    }
    vector<int> x(n);
    vector<int> y(n);
    rep(i,n){
        cin >> x[i];
    }
    rep(i,n){
        cin >> y[i];
    }
    int k = 0;
    int ansx = 0;
    int ansy = 0;
    while(next_permutation(norm.begin(),norm.end())){
        k++;
        if (norm == x){
            ansx = k;
        }
        if (norm == y){
            ansy = k;
        }
    }
    int ans = abs(ansx - ansy);
    cout << ans << endl;
    
}