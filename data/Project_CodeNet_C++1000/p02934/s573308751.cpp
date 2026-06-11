#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    double bunbo = 0;
    rep(i,n){
        double a;
        cin >> a;
        bunbo += 1/a;
    }
    printf("%.10f\n",1/bunbo);
}