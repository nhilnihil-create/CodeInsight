#include<iostream>

using namespace std;
main(){
  int n,s1,s2;
  int a,b;
  cin>>n;
  while(n!=0){
    s1=s2=0;
    for(int i=0;i<n;i++){
      cin>>a>>b;
      if(a>b)
	s1+=(a+b);
      else if(a<b)
	s2+=(a+b);
      else{
	s1+=a;
	s2+=a;
      }

    }
    cout<<s1<<" "<<s2<<endl;
    
    cin>>n;
  }
  return 0;
}