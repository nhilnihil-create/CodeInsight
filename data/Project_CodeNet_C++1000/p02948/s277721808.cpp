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

int main(){
    int n,m;cin>>n>>m;
    vvin ptj(100050);//part time job
    int a,b;
    rep(i,n){
        cin>>a>>b;
        ptj[a].push_back(b);
    }
    int ans=0;
    priority_queue<int> pq;//m-i日の時点で始めることのできる仕事の中で報酬が最大のものを取り出す
    rep2(i,1,m+1){
        if(ptj[i].size()){
            for(auto p:ptj[i])pq.push(p);
        }
        if(pq.size()){
            ans+=pq.top();
            pq.pop();
        }
    }
    cout<<ans<<endl;
}