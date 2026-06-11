#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    rep(i,n) cin >> a.at(i+1);
    vector<int> b(n+1);
    for(int i=n;i>=1;i--){
        int x = 0;
        for(int j=2;i*j<=n;j++){
            x = (x + b.at(i*j)) % 2;
            // if(i==1) cout << i*j << " " << b.at(i*j) << endl;
        }
        // cout << i << " " << x << endl;
        b.at(i) = (x + a.at(i)) % 2;
    }
    vector<int> c;
    rep(i,n+1){
        if(b.at(i) == 1) c.push_back(i);
    }

    cout << c.size() << endl;
    rep(i,c.size()){
        if(i>0) cout << " ";
        cout << c.at(i);
    }
    if(c.size()) cout << endl;
    return 0;
}