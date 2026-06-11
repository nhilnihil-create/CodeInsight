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
    int b[n];
    int a[n]; rep(i, n){
        cin >> a[i];
        b[i] = a[i];
    }
    int cnt = 0;
    sort(b, b+n);
    rep(i, n){
        for(int j = i; j < n; ++j){
            swap(a[i], a[j]);
            rep(k, n){
                if(a[k] == b[k]){++cnt;}
            }
            if(cnt == n){cout << "YES" << endl; return 0;}
            swap(a[i], a[j]);
            cnt = 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}