#include <iostream>
#include <string>
using namespace std;
int main()
{
  int num[31];
  int temp;
  int ans=0;
  int ans2=0;
  int i;
  for(i=1;i<=30;i++){
      cin>>temp;
      num[temp]=1;
  }
  
  for(i=1;i<=30;i++){
      if(num[i]!=1&&ans==0){
          ans=i;
      }else if(num[i]!=1&&ans!=0){
          ans2=i;
      }
  }
  if(ans<=ans2){
      cout<<ans<<endl;
      cout<<ans2<<endl;
  }else{
      cout<<ans2<<endl;
      cout<<ans<<endl;
  }
  return 0;
  
}