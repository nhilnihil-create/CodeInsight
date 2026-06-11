#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  vector<int>l(n);
  int64_t ans=0;
  for(int i=0;i<n;i++){
    cin>>l.at(i);
  }
  sort(l.begin(),l.end());
  for(int i=0;i<n-2;i++){
    for(int j=i+1;j<n-1;j++){
      for(int k=j+1;k<n;k++){
        if(l.at(i)+l.at(j)<=l.at(k))break;
        if(l.at(i)+l.at(j)>l.at(k)&&(l.at(j)+l.at(k)>l.at(i)&&l.at(i)+l.at(k)>l.at(j)))ans++;
      }
    }
  }
  cout <<ans<<endl;
}