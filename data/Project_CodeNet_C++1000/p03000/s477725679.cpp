#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    int n, x;
    cin >> n >> x;
    int l[n]; rep(i, n){cin >> l[i];}
    int c[n+1];
    c[0] = 0;
    rep(i, n){
        c[i+1] = l[i] + c[i];
    }
    int cnt = 0;
    rep(i, n+1){
        if(c[i] <= x){++cnt;}
    }
    
    cout << cnt << endl;
}