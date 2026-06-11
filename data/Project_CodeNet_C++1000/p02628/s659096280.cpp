#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main(){
  int n,k;
  cin>>n>>k;
  vector<int> temp(n);
  for(int& i:temp)
    cin>>i;
  int ans=0;
  sort(temp.begin(),temp.end());
  for(int i=0;i<k;i++){
    ans+=temp[i];
  }
  cout<<ans<<endl;
  return 0;
}