#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
#define mp make_pair
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<int>>;
#define MAX 1000000


int main()
{
    int n,x,y;
    cin >> n;
    cin >> x >> y;
    
    vector<int> dist_count(n,0);
    Graf dist(n+1,vector<int>(n+1));
    vector<bool> found(n+1,false);
    queue<P> q;
    int count=0;
    FOR(i,n+1,1){
        FOR(j,n+1,1){
            found[j]=false;
        }
        
        q.push(mp(i,0));
        
        while(!q.empty()){
            P p=q.front();
            int now=p.first;
            int val=p.second;
            q.pop();
            if(found[now]!=true){
                found[now]=true;
                dist[i][now]=val;
                dist[now][i]=val;
                
                if(now-1>0){
                    if(found[now-1]==false)
                        q.push(mp(now-1,val+1));
                }
                if(now+1<=n){
                    if(found[now+1]==false)
                        q.push(mp(now+1,val+1));
                }
                if(now==x){
                    if(found[y]==false)
                        q.push(mp(y,val+1));
                }
                if(now==y){
                    if(found[x]==false)
                        q.push(mp(x,val+1));
                }
            }
        }
    }
    FOR(i,n,1){
        for(int j=i+1;j<n+1;++j){
            dist_count[dist[i][j]]++;
        }
    }
    rep(i,n-1){
        cout << dist_count[i+1] << endl;
    }
}