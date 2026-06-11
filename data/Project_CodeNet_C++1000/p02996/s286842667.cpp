#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


int main(){
    int n;cin>>n;
    vector<pair<int,int>>pairs(n);
    for(int i = 0;i<n;i++){
        int x,y;cin>>x>>y;
        //期限が早いもの順にソート
        pairs[i]=make_pair(y,x);
    }

    sort(pairs.begin(),pairs.end());
    ll count = 0;
    int x = 0;
    rep(i,n){
        count+=pairs[i].second;
        x = pairs[i].first;

        if(pairs[i].first<count){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;

}
