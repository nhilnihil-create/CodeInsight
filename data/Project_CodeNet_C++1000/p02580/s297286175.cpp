#include <bits/stdc++.h> 
using namespace std; 
int mod = 1000000007;

int main() 
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        long long h,w,m;cin>>h>>w>>m;
        vector <pair<long long,long long>> hh;
        for(int i=0;i<m;i++){
            int x,y;cin>>x>>y;
            hh.push_back({x,y});
        }
        map <int,int> cnt[2];
        for(auto x:hh){
            cnt[0][x.first]++;
            cnt[1][x.second]++;
        }
        int maxcnt[2]={0,0};
        for(auto x:cnt[0])
            maxcnt[0]=max(maxcnt[0],x.second);
        for(auto x:cnt[1])
            maxcnt[1]=max(maxcnt[1],x.second);
        set <int> s[2];
        for(auto x:cnt[0])if(maxcnt[0]==x.second)s[0].insert(x.first);
        for(auto x:cnt[1])if(maxcnt[1]==x.second)s[1].insert(x.first);
        int count=0;
        for(auto x:hh){
            if(s[0].find(x.first)!=s[0].end() && s[1].find(x.second)!=s[1].end())count++;
        }
        if(count==s[0].size()*s[1].size())cout<<maxcnt[0]+maxcnt[1]-1<<"\n";
        else cout<<maxcnt[0]+maxcnt[1]<<"\n";
    }
    return 0; 
} 