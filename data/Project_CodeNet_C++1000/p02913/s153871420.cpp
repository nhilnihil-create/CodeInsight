// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1e18+7;
const int inf=1e9+7;
using P=pair<int,int>;
vector<int> dx={0,1,-1,0};
vector<int> dy={1,0,0,-1};



int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    int n;
    string s;
    cin>>n>>s;
    vector<vector<int>> place(26,vector<int>(0));
    rep(i,n) place[s[i]-'a'].emplace_back(i);
    vector<int> now(26,0);
    int ans=0;
    rep(i,n-1){
        int num=s[i]-'a';
        now[num] ++;
        if(now[num]==place[num].size()) continue;
        for(int j=now[num];j<place[num].size();j++){
            int x=place[num][j];
            if(i>=x) continue;
            if(i>0 && s[i-1]==s[x-1]) continue;
            int cnt=0;
            while(x+cnt<n){
                if(i+cnt==x) break;
                if(s[i+cnt]==s[x+cnt]) cnt ++;
                else break;
            }
            ans=max(ans,cnt);
        }
    }
    cout<<ans<<endl;
}/*
./problem.exe
*/