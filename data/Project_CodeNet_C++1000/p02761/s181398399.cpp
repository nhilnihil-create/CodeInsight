#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n,-1);
    rep(i,m){
        int s,c;
        cin >> s >> c;
        if(v[n-s] != -1 && v[n-s] != c){
            cout << -1 << endl;
            return 0;
        }
        v[n-s] = c;
    }
    if(v[n-1]==0) {
        if(n==1){
            cout << 0 << endl;
            return 0;
        }
        cout << -1 << endl;
        return 0;
    }
    if(v[n-1]==-1){
        if(n==1) v[0] = 0;
        else v[n-1] = 1;
    }
    rep(i,n){
        if(v[i]==-1){
            v[i]=0;
        }
    }
    for(int i=n-1; i>=0; i--){
        cout << v[i];
    }
    cout << endl;
    return 0;
}