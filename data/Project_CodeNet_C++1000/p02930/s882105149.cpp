#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;
  cin>>n;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      int kb=i^j,cnt=1;
      while(kb%2==0){
        kb/=2;
        cnt++;
      }
      cout<<cnt<<" ";
    }
    cout<<endl;
  }
}
