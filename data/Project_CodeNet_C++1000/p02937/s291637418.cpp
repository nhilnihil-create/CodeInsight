#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll INF=1LL<<60;
const int MOD=1e9+7;

int main(){
    vector<set<int>> id(26);
    string s, t; cin >> s >> t;
    for(int i=0; i<s.size(); i++){
        id[s[i]-'a'].insert(i);
    }
    bool ans=true;
    ll res;
    ll len=s.size(), cnt=0;
    for(int i=0; i<t.size(); i++){
        if(id[t[i]-'a'].empty()) ans=false;
        else if(i == 0) res=*begin(id[t[i]-'a']);
        else{
            int val=res-len*cnt;
            auto it=id[t[i]-'a'].upper_bound(val);
            if(it != id[t[i]-'a'].end()) res=len*cnt+*it;
            else{
                cnt++;
                res=len*cnt+*begin(id[t[i]-'a']);
            }
        }
    }
    res++;
    cout << (ans ? res:-1) << endl;
    return 0;
}