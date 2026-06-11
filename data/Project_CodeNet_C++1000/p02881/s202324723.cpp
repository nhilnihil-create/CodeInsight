#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
int main(){
  long long int n,a,b,mini;cin>>n;
  mini=n-1;
  for(long long int i=2;i<=n/i;i++){
      if(n%i==0){
        a=i;b=n/i;
        if(a+b-2 < mini)mini=a+b-2;
      }
  }
   cout<<mini;
  return 0;
}