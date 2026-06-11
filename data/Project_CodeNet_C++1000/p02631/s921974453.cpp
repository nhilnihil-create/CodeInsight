#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    ll sum=0;
    rep(i,n){
        cin >> a[i];
        sum = sum ^ a[i];
    }
    rep(i,n){
        int ans=0;
        ans = sum ^ a[i];
        cout << ans << endl;
    }
}