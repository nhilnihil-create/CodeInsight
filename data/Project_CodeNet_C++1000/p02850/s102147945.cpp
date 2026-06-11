#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
const long long MOD=1e09+7;



#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define pb push_back



map<pii,int> edgecolor;
vector<pii> data;
vector<vi> to(100005,vi(0));




void dfs(int node, int used){
  int color=1;
  for (int next:to.at(node)){
    if (color==used){
      color++;
    }
    
    int smaller=min(node,next);
    int bigger=max(node,next);
    auto edge=make_pair(smaller,bigger);
    if (edgecolor.find(edge)!=edgecolor.end()){
      continue;
    }
    edgecolor[edge]=color;
    dfs(next,color);
    color++;
  }
}



int main(){
  
  int n;
  cin>>n;
  

  rep(i,n-1){
    int a,b;
    cin>>a>>b;
    auto tmp=make_pair(a,b);
    data.pb(tmp);
  }
  
  
  rep(i,n-1){
    int a=data.at(i).first;
    int b=data.at(i).second;
    to.at(a).pb(b);
    to.at(b).pb(a);
  }

  
  dfs(1,0);
  
  vi answers(0);
  
  int maxcolor=0;
  
  rep(i,n-1){
    int color=edgecolor.at(data.at(i));
    answers.pb(color);
    maxcolor=max(maxcolor,color);
  }
  
  cout<<maxcolor<<endl;
  for (int answer:answers){
    cout<<answer<<endl;
  }

  
}


















