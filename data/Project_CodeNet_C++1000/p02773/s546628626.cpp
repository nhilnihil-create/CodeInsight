#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
using Grid= vector<vector<char>>;
using vin= vector<int>;
using ll=long long;
using vll= vector<ll>;
using vbl=vector<bool>;
using vch=vector<char>;
using pinin=pair<int ,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rell(i,n) for (ll i=0; i< (ll)(n); i++)
#define sort(x) sort(x.begin(), x.end());
#define rese(x) reverse(x.begin(), x.end());

string yes="Yes",no="No";

int main() {
    int n;
    cin>>n;
    set<string> s;
    map<string ,int> u;
    rep(i,n){
        string t;
        cin>>t;
        if(s.count(t)){
            u[t]++;
        }
        else{
            u[t]=1;
            s.insert(t);
        }
    }
    int ahu=0;
    for(auto p: u){
        ahu=max(ahu,p.second);
    }
    set<string> ans;
    for(auto p:u){
        if(ahu==p.second){
            ans.insert(p.first);
        }
    }
    for(auto p:ans ){
        cout<<p<<endl;
    }
  
}
