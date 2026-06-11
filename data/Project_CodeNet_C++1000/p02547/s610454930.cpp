#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
typedef long long ll;

int main(){
    int n; cin>>n;
    vector<bool> v(n);
    rep(i,n){
        int a,b; cin>>a>>b;
        v[i] = (a==b);
    }
    for(int i=2;i<n;i++){
        if(v[i]==1&&v[i-1]==1&&v[i-2]==1){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}