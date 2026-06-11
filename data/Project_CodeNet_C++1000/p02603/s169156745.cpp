#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;
#define int long long

signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int money = 1000;
    rep(i,n - 1){
        if(a[i] < a[i+1]){
            int stock = money / a[i];
            money += (a[i+1] - a[i]) * stock;
        }
    }
    cout << money << endl;
}