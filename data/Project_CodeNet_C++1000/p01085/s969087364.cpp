#include<bits/stdc++.h>
using namespace std;
int main(){
  int m,s,g,p[200];
  while(cin>>m>>s>>g,m){
    int ans=-1,an;
    for(int i=0;i<m;i++)cin>>p[i];
    sort(p,p+m,greater<int>());
    for(int i=g;i>=s;i--)if(ans<p[i-1]-p[i])ans=p[i-1]-p[i],an=i;
    cout<<an<<endl;
  }
  return 0;
}