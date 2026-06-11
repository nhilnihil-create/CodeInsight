#include<iostream>

using namespace std;
main(){
  int i,j;
  int n,m;
  cin>>n;
  while(n!=0){
    char t[n][2];
    for(i=0;i<n;i++)
      cin>>t[i][0]>>t[i][1];
  
    cin>>m;
 
    char ans[m+1];
  
    for(i=0;i<m;i++){
      cin>>ans[i];
      for(j=0;j<n;j++){
	if(t[j][0]==ans[i]){
	  ans[i]=t[j][1];
	  break;
	}
      }
    }
    ans[i]='\0';

    cout<<ans<<endl;
    cin>>n;  
  }

  return 0;
}