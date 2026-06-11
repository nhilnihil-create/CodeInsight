
#include<bits/stdc++.h>
using namespace std;

int main(){
  cout<<fixed<<setprecision(12);


  while(1){
    int n;
    double s[1000];
    double sum=0;

    cin>>n;
    
    if(n==0){
      break;
    }
    
    for(int i=0;i<n;i++){
      cin>>s[i];
    }
  
    for(int i=0;i<n;i++){
      sum+=s[i];
    }
  
    double avg=sum/n;

    double ans=0;
  
    for(int i=0;i<n;i++){
      ans+=pow(s[i]-avg,2);
    }

    ans=sqrt( ans/n );
  
    cout<<ans<<endl;
  }
}
