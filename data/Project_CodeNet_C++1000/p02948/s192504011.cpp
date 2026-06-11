#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int n, m;
    cin>>n>>m;
    vector<pair<int, int> > v(n);
    rep(i, n){
        int a, b;
        cin>>a>>b;
        v[i] = make_pair(b, m-a);//報酬, 働かなければならない日
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    set<int> canwork;
    rep(i, m) canwork.insert(-i);
    int res = 0;
    rep(i, n){
        int money = v[i].first;
        int day = v[i].second;
        if(canwork.find(-day) != canwork.end()) {
            canwork.erase(-day);
            res += money;
        }
        else{
            auto itr = canwork.lower_bound(-day);
            if(itr == canwork.end()) continue;
            int s = *itr;
            canwork.erase(s);
            res += money;
        }
    }
    cout<<res<<endl;
    return 0;
}