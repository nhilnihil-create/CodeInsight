#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<set>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
#define INF 1000000100
#define rep(i,n) for (int i=0;i<n;i++)

string s,t;
map<int,vector<int>> mp;
set<int> sets;

int check(int l,int r, int pre){
    int next=-1;
    int now=t[r-1];
    if(sets.find(now)==sets.end()){
        return -10;
    }
    auto itr = find(mp[now].begin(), mp[now].end(), pre); 
    if(itr!=mp[now].end()){
        if(itr==mp[now].end()-1){
            return -1;
        }
        itr++;
        return *itr;
    }
    rep(i,mp[now].size()){
        if(mp[now][i]>pre){
            next=mp[now][i];
            return next;
        }
    }
    return next;
}

int main(){
    cin >> s >> t;
    rep(i,s.size()){
        mp[s[i]].push_back(i);
        sets.insert(s[i]);
    }
    int sum=0;
    int l=0, r=1;
    int next=-1; 
    int pre=-1;
    while(l<t.size() && r<t.size()+1){
        next = check(l,r,pre);
        if(next==-10){
            cout << -1 << endl;
            return 0;
        }
        if(next!=-1){
            r++;
            pre=next;
        }
        else{
            sum+=1;
            l=r-1;
            pre=-1;
        }

    }
    ll ans = sum*s.size()+pre+1;
    cout << ans << endl;
    return 0;
}