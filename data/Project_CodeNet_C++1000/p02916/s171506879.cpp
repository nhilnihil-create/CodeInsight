#include<bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    
    int n;
    cin >> n;
    int a[n], b[n], c[n];
    rep(i, n){cin >> a[i];}
    rep(i, n){cin >> b[i];}
    rep(i, n-1){cin >> c[i];}
    int sum=0;
    rep(i, n){
        sum += b[a[i]-1];
    }
    
    rep(i, n-1){
        if(a[i+1]-a[i] == 1){
            sum += c[a[i]-1];
        }
    }
    cout << sum << endl;
}