#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,ans=0;
  cin>>n;
  for(int i=1;i<=n;i++){
    if(i%2!=0){
      ans++;
    }
  }
  cout<<fixed<<setprecision(20)<<(double)ans/n<<endl;
}