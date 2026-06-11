#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll n;

void dfs(string now, vector<string> &vec,ll d){
    if(now.length()==n){
        vec.push_back(now);
        return;
    }
    for(ll i=0;i<=d;i++){
        string next=now+char('a'+i);
        ll m=d;
        if(i==d) m++;
        dfs(next,vec,m);
    }
}
int main() {
    cin >> n;
    vector<string>ans;
    dfs("a",ans,1);
    for(ll i=0;i<ans.size();i++){
        cout << ans[i] << endl;
    }
}