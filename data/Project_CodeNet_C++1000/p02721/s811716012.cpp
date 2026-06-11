#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    string s;
    int n, k, c, sa = 0;
    cin >> n >> k >> c >> s;
    vector<int> a(n, -1), b(n, -1);
    while(s[sa] == 'x')sa++; 
    a[sa] = 1;
    int cnt = 0, sum = 1;
    for(int i = sa+1; i < n; i++){
        if(sum >= k)break;
        if(cnt >= c && s[i] == 'o'){
            sum++;
            a[i] = sum;
            cnt = 0; 
        }
        else cnt++;
    }
    cnt = 0; sum = 1;
    int sb = 0;
    reverse(all(s));
    while(s[sb] == 'x')sb++; 
    b[sb] = k;
    for(int i = sb+1; i < n; i++){
        if(sum >= k)break;
        if(cnt >= c && s[i] == 'o'){
            sum++;
            b[i] = k-sum+1;
            cnt = 0;
        }
        else cnt++;
    }
    reverse(all(b));
    rep(i, n)if(a[i] == b[i] && a[i] != -1)cout << i+1 << endl;
}