#include<bits/stdc++.h>
using namespace std;
void tree(vector<set<int>> &g,vector<vector<int>> &t,int p){
  while(!g.at(p).empty()){
    int cp=*begin(g.at(p));
    t.at(p).push_back(cp);
    g.at(p).erase(cp);
    g.at(cp).erase(p);
    tree(g,t,cp);
  }
  return;
}
void color(vector<vector<int>> &t,vector<int> &c,int k,int d,int p){
  for(int i=0;i<t.at(p).size();i++){
    c.at(t.at(p).at(i))=k-min(d,2)-i;
    color(t,c,k,d+1,t.at(p).at(i));
  }
  return;
}
int main(){
  int n,k;
  cin>>n>>k;
  vector<set<int>> g(n);
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    g.at(a-1).insert(b-1);
    g.at(b-1).insert(a-1);
  }
  vector<vector<int>> t(n);
  tree(g,t,0);
  vector<int> c(n);
  c.at(0)=k;
  color(t,c,k,1,0);
  int64_t p=1;
  for(int i=0;i<n;i++)
    p=p*c.at(i)%1000000007;
  cout<<p<<endl;
}