#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;

int n;
vvin edge(100050);
map<pair<int,int>,int> e;

void bfs(){
    queue<pair<int,int>> q;
    q.push(mp(1,0));
    vbo arrived(n+1,false);arrived[1]=true;
    int j;
    while(q.size()){
        auto p=q.front();q.pop();
        if(edge[p.first].size()==0)continue;
        j=1;
        for(auto hen:edge[p.first]){
            if(j==p.second)j++;
            if(!arrived[hen]){
                if(p.first<hen)e[mp(p.first,hen)]=j;
                else e[mp(hen,p.first)]=j;
                q.push(mp(hen,j));
                arrived[hen]=true;
                j++;
            }
        }
    }
}

int main(){
    cin>>n;
    vector<set<int>> used(n+1);
    vin a(n-1),b(n-1);
    rep(i,n-1){
        cin>>a[i]>>b[i];
        edge[a[i]].push_back(b[i]);
        edge[b[i]].push_back(a[i]);
    }
    int M=0;int tmp;
    rep(i,n){
        tmp=edge[i+1].size();
        M=max(M,tmp);
    }
    bfs();
    cout<<M<<endl;
    rep(i,n-1){
        if(a[i]<b[i])cout<<e[mp(a[i],b[i])]<<endl;
        else cout<<e[mp(b[i],a[i])]<<endl;
    }
}