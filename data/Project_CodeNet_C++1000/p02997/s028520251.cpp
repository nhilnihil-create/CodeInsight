#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n,k;
    cin >> n >> k;
    int lmx = (n-1) * (n-2) / 2;
    if(k > lmx) {
        cout << "-1" << endl;
        return 0;
    }
    vector<pair<int,int>> vp;
    // star
    rep(i,n-1){
        vp.push_back({1,i+2});
    }
    int adl = lmx-k;
    int cur = 0;
    for(int i=2;i<=n-1 && cur<adl;i++){
        for(int j=i+1;j<=n && cur<adl;j++){
            vp.push_back({i,j});
            cur++;
        }
    }
    cout << vp.size() << endl;
    rep(i,vp.size()){
        cout << vp.at(i).first << " " << vp.at(i).second << endl;
    }
    return 0;
}