#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


int main(){
    int n,k;
    cin  >> n >> k;
    vector<int> a(n);
    int amin = 1;
    int amax = 1;
    rep(i,n) {
        cin >> a[i];
        amax = max(amax,a[i]);
    }
    ll sum =0;
    rep(i,n){
        sum += a[i];
    }

    if(sum <= k){
        cout << 1 << endl;
        return 0;
    }
    int x = 1;
    while(amax-amin>1){
        //cout << amax << " " <<amin << endl;
        sum = 0;
        x = (amax+amin)/2;
        rep(i,n){
            sum += a[i]/x;
            if(a[i]%x==0) sum--;
        }
        //cout << " " << sum << endl;
        if(sum<=k) amax = x;
        else amin = x;
    }

    cout << amax << endl;



 }