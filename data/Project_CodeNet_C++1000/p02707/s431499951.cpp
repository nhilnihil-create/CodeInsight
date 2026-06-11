#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
char in[120];
pair<pair<string,int>,int> p[110];
int main(){
    int n;
    cin >> n;
    int a[n];
    int cnt[n];
    rep(i, n){cnt[i] = 0;}
    for(int i = 2; i <= n; ++i){
        cin >> a[i];
        cnt[a[i]-1] += 1; 
    }
    rep(i, n){cout << cnt[i] << endl;}
    return 0;
}