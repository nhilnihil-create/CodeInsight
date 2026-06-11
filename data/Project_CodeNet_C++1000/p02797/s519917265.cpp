#include <bits/stdc++.h>
using namespace std;


int main() {

  int n,k,s;
  cin>>n>>k>>s;
  

  vector<int> A(n+1);
  for(int i=1;i<=n;i++){
    if(i<=k)
      A.at(i)=s;
    else if(s==1000000000){
      A.at(i)=1000000000-1;
    }else{
      A.at(i)=1000000000;
    }
  }   


    for(int i=1;i<=n;i++){
      if(i<n)
        cout<<A.at(i)<<" ";
      else
      {
       cout<<A.at(i)<<endl;
      }
    }

    return 0;
}
