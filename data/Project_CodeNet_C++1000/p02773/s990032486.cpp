#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pipii;
typedef long long ll;
typedef pair<ll,ll> pll;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e18;
const ll MOD=1e9+7;
struct edge{
    int to;
    int cost;
};
int main(){
    int N;cin>>N;
    map<string,int> mp;
    for(int i=0;i<N;++i){
        string s;cin>>s;
        mp[s]++;
    }
    int mx=0;
    for(auto it:mp){
        if(it.second>mx) mx=it.second;
    }
    vector<string> ans;
    for(auto it:mp){
        if(it.second==mx) ans.push_back(it.first);
    }
    sort(ans.begin(),ans.end());
    for(auto it:ans){
        cout<<it<<endl;
    }
    return 0;
}