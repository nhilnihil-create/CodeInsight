#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    int n;
    cin >> n;
    int p[n]; rep(i, n){cin >> p[i];}
    int b[3]={};
    int cnt = 0;
    rep(i, n-2){
        b[0] = p[i];
        b[1] = p[i+1];
        b[2] = p[i+2];
        sort(b, b+3);
        if(b[1] == p[i+1]){++cnt;}
    }
    cout << cnt << endl;
    return 0;
}