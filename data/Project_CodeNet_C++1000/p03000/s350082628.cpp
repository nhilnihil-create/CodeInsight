#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,x;
  cin>>n>>x;
  vector<int>l(n+1);
  l.at(0)=0;
  for(int i=0;i<n;i++){
    int y=0;
    cin>>y;
    l.at(i+1)=l.at(i)+y;
  }
  int ans=0;
	for(int i=0;i<=n;i++){
      if(l.at(i)<=x){
        ans++;
      }
    }
  cout<<ans<<endl;
}
  
