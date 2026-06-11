#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
typedef long long ll;

int main(){
    int x,y,a,b,c; cin >>x>>y>>a>>b>>c;
    int p[a],q[b],r[c];
    vector<pair<int, int> > all;
    rep(i,a){ cin >> p[i]; all.push_back({p[i],1});}
    rep(i,b){ cin >> q[i]; all.push_back({q[i],2});}
    rep(i,c){ cin >> r[i]; all.push_back({r[i],0});}
    sort(all.rbegin(), all.rend());
    int red=0, green=0, eat=0, i=0;
    ll ans = 0;
    while(eat < x+y){
        //cout << all[eat].first << endl;
        if(all[i].second == 1){
            if(red < x){ ans+=all[i].first; eat++;}
            red++;
        }else if(all[i].second == 2){
            if(green < y){ ans+=all[i].first; eat++;}
            green++;
        }else{
            ans+=all[i].first;
            eat++;
        }
        //cout<<"eat " << eat << endl;
        //cout << "ans "<< ans << endl;
        i++;
    }
    cout << ans << endl;
    
}