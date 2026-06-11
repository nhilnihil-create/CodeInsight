#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
const ll INF=1LL<<60;
const ll MOD=1000000007;



int main(){
    string s;
    cin >> s;
    string t;
    cin >> t;
    ll u=s.size();
    ll v=t.size();
    map<char,vl> M;
    for(ll i=0;i<u;i++){
        M[s[i]].emplace_back(i);
    ;}
    ll round=0;
    ll mark=-1;
    for(ll i=0;i<v;i++){
        char T=t[i];
        if(M[T].empty()){cout<<-1<<endl;return 0;}
        else if(upper_bound(M[T].begin(), M[T].end(), mark)!=M[T].end())
            mark=*upper_bound(M[T].begin(), M[T].end(), mark);
        else {
            round++;
            mark=M[T][0];
        }
    ;}
    cout<<round*u+mark+1LL<<endl;
    return 0;
}
