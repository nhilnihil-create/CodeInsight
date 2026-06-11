#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i =0;i<(int)(n);i++)
#define endl '\n'
typedef pair<int,int> P;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    ll res = 0;
    sort(a.begin(),a.end());
    for(int i=1;i<n;i++){
        res+=a[n-1-i/2];
    }
    cout << res << endl;
}