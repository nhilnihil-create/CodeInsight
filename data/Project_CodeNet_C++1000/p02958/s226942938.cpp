#include<iostream>
using namespace std;
int main(){
int n,i,f=0;
cin>>n;
int p[n];
  for( i=1;i<=n;i++){
    cin>>p[i];
  }
  i=0;
   for(i=1;i<=n;i++){
if(p[i]!=i){f++;}
    }
    if(f<=2){
    cout<<"YES"<<endl;
}
else{
    cout<<"NO"<<endl;
}



}
