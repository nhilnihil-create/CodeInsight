#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    map<int,int> ac;
    map<int,int> wa;
    int n,m;
    cin >> n >> m;

    rep(i,m){
        int p;
        string s;
        cin >> p >> s;

        if(s=="AC"){
            ac[p]++;
        }else{
            if(!ac.count(p))
                wa[p]++;
        }
    }

    int ans_wa(0);
    for(auto a : wa){
        if(ac.count(a.first))
            ans_wa += a.second;
    }

    cout << ac.size() << " " << ans_wa << endl;
 
    return 0;
}