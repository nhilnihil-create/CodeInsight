#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;++i)

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

vector<set<int>> node;
vector<int> searched;

void solve(int index){
    searched[index]=index;
    queue<int> que; que.push(index);
    while(!que.empty()){
        int order = que.front(); que.pop();
        for(auto itr=node[order].begin();itr!=node[order].end();++itr){
          if(-999==searched[*itr])que.push(*itr);
            searched[*itr]=index;
        }
    }
}

int main(){
   int n,m;cin>>n>>m;
   node.resize(n);
   searched.resize(n,-999); 
   REP(i,m){
    int x,y;cin>>x>>y;
    node[x].insert(y);
    node[y].insert(x);
   }
   REP(i,n)
    if(-999==searched[i])
      solve(i);
   int hm;cin>>hm;
    REP(i,hm){
      int x,y;
      cin>>x>>y;
      if(searched[x]==searched[y]&&searched[y]!=-999&&searched[x]!=-999)
        cout << "yes" << endl;
      else 
        cout << "no" << endl;
    }
}
