#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,M=1e9+7;
const int LINF = 0x3f3f3f3f3f3f3f3f;
//did u check when n=1?
//is mxN correct?
map<string,int>mp;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        mp[s]++;
    }
    int ma=0;
    for(auto it=mp.begin();it!=mp.end();it++){
        ma=max(ma,it->second);
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second==ma)cout<<it->first<<"\n";
    }
    
}