#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n,m,tmp,cnt=0;
  vector <int> a,spread;
 
  cin>>n;
  for(int i=0;i<n;i++){ //input original
    cin>>tmp;
    a.push_back(tmp);
  }
  for(int i=0,tmp=1;tmp<=n;i++){ //make spread vector
    spread.insert(spread.begin(),tmp);
    tmp=3*tmp+1;
  }
  m=spread.size();
  cout<<m<<endl; //output spread amount
  for(int i=0;i<m-1;i++) cout<<spread[i]<<" ";
  cout<<spread[m-1]<<endl; //output all spread
  
  for(int k=0;k<m;k++){  //testing all spread
    for(int i=spread[k];i<n;i++){
      tmp=a[i];
      int j=i-spread[k];
      while(j>=0&&a[j]>tmp)
      {
        a[j+spread[k]]=a[j];
        j-=spread[k];
        cnt++;
      }
      a[j+spread[k]]=tmp;
    }
  }
  cout<<cnt<<endl; //output cnt&answer vector
  for(int i=0;i<n;i++) cout<<a[i]<<endl;
  return 0;
}