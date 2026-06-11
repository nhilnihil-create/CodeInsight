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
    double ans = 0;
    double a[n]; rep(i, n){
        cin >> a[i];
        ans += 1/a[i];
    }
    cout << 1/ans << endl;
    
}