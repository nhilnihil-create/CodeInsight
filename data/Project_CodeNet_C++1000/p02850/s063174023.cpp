#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    int N; cin>>N;
    vector<pair<int,int>> Edge;
    vector<vector<int>> G(N);
    rep(i,0,N-1){
        int a,b; cin>>a>>b;
        Edge.emplace_back(a-1,b-1);
        G.at(a-1).push_back(b-1);
        G.at(b-1).push_back(a-1);
    }

    map<pair<int,int>,int> Mp;
    vector<int> Used(N,0),cParent(N,0);
    int K=0;

    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int n=q.front(); q.pop();

        Used.at(n)=1;
        K=max(K,(int)G.at(n).size());

        int c=1;
        for(auto g:G.at(n)){
            if(Used.at(g)) continue;

            if(c==cParent.at(n)) c++;
            cParent.at(g)=Mp[make_pair(n,g)]=Mp[make_pair(g,n)]=c++;
            
            q.push(g);
        }
    }

    cout<<K<<endl;
    for(auto e:Edge) cout<<Mp[e]<<endl;
}