#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    // Your code here!
    int n, m;
    cin >> n >> m;
    int a[n];
    int ans=0;
    rep(i, n){cin >> a[i]; ans+= a[i];}
    sort(a, a+n, greater<int>());
    double ans2 = ans/4.0/m;
    rep(i, m){
        if(a[i] < ans2){cout << "No" << endl; return 0;}
    }
    cout << "Yes" << endl;
    return 0;
}