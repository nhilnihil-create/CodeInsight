#include<bits/stdc++.h>
using namespace std;
void f(int k,int pa,int pac,vector<vector<int>> &g,vector<vector<int>> &t,int &tcnt){
  int co=1;
  for(auto i:g.at(k)){
    if(i!=pa){
      if(co==pac) co++;
      t.at(tcnt).push_back(min(k,i));
      t.at(tcnt).push_back(max(k,i));
      t.at(tcnt).push_back(co);
      tcnt++;
      f(i,k,co,g,t,tcnt);
      co++;
    }
  }
}
int main(){
  int n,a,b,i,mi=0,tcnt=0;
  cin>>n;
  vector<vector<int>> g(n+1,vector<int>(0)),t1(n-1,vector<int>(1)),t2(n-1,vector<int>(0));
  for(i=0;i<n-1;i++){
    cin>>a>>b;
    g.at(a).push_back(b);
    g.at(b).push_back(a);
    t1.at(i).push_back(a);
    t1.at(i).push_back(b);
    t1.at(i).push_back(i);
  }
  for(i=1;i<=n;i++) if(mi<g.at(i).size()) mi=g.at(i).size();
  cout<<mi<<endl;
  f(1,0,0,g,t2,tcnt);
  sort(t1.begin(),t1.end());
  sort(t2.begin(),t2.end());
  for(i=0;i<n-1;i++){
    t1.at(i).push_back(t2.at(i).at(2));
    t1.at(i).at(0)=t1.at(i).at(3);
  }
  sort(t1.begin(),t1.end());
  for(i=0;i<n-1;i++) cout<<t1.at(i).at(4)<<endl;
}