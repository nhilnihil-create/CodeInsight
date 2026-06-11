#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  vector<int> a(n);
  for(int i=0;i<n;i++)
    cin>>a.at(i);
  for(int _=0;_<k;_++){
    vector<int> p=a;
    vector<int> d(n+1,0);
    for(int i=0;i<n;i++){
      d.at(max(i-p.at(i),0))++;
      d.at(min(i+p.at(i)+1,n))--;
    }
    a.at(0)=d.at(0);
    for(int i=1;i<n;i++)
      a.at(i)=a.at(i-1)+d.at(i);
    if(p==a)
      break;
  }
  for(int i=0;i<n;i++)
    cout<<a.at(i)<<(i+1<n?" ":"");
  cout<<endl;
}