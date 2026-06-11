/**
*    author:  souzai32
*    created: 21.08.2020 23:18:47
**/

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
typedef long long ll;
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<pair<int,bool>>> xy(n,vector<pair<int,bool>>(n));
    int x,y;
    rep(i,n){
        cin >> a[i];
        rep(j,a[i]){
            cin >> x >> y;
            xy[i][j]=make_pair(x-1,y);
        }
    }
    bool ans;
    int num=0;

    for(int bit=0; bit<(1<<n); bit++){
        // cout << bitset<8>(bit) << endl;
        ans=true;
        for(int i=0; i<n; i++){
            if(bit&(1<<i)){
                for(int j=0; j<a[i]; j++){
                    if(get<1>(xy[i][j])&&!(bit&(1<<get<0>(xy[i][j])))){
                        ans=false; //cout << 0;
                    }else if(!get<1>(xy[i][j])&&bit&(1<<get<0>(xy[i][j]))){
                        ans=false; //cout << 0;
                    }//else cout << 1;
                    //cout << endl;
                }
            }
        }
        if(ans) num=max(num,__builtin_popcount(bit));
    }

    cout << num << endl;
    return 0;
}