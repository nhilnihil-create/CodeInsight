#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  int ans=0;
  cin>>N;
  ans=N/1.08;
  if(floor(ans*1.08)==N){
    cout<<ans<<endl;
  }
  else if(floor((ans+1)*1.08)==N){
    cout<<ans+1<<endl;
  }
  else{
    cout<<":("<<endl;
  }
}
