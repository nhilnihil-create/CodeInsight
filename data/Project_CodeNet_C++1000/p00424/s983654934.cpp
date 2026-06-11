#include <iostream>
using namespace std;
int main(void){
  char a[100000],b[100000],c;
  int m,n,f;
  while(1){
    cin>>n;
    if(!n)
      break;
    for(int i=0;i<n;i++)
      cin>>a[i]>>b[i];
    cin>>m;
    for(int j=0;j<m;j++){
      f=1;
      cin>>c;
      for(int k=0;k<n;k++){
	if(c==a[k]){
	  f=0;
	  cout<<b[k];
	  break;
	}
      }
      if(f)
	cout<<c;
    }
    cout<<endl;
  }
  return 0;
}