#include<iostream>
using namespace std;

int main(){
 int n;
 int Acard,Bcard,Apoint,Bpoint;
 while(true){
  cin>>n;
  if(n==0){
   break;
  }else{
    for(int i=0;i<n;i++){
     cin>>Acard>>Bcard;
     if(Acard>Bcard){
      Apoint+=Acard+Bcard;
     }else if(Acard<Bcard){
      Bpoint+=Acard+Bcard;
     }else{
      Apoint+=Acard;
      Bpoint+=Bcard;
     }
    }
   cout<<Apoint<<' '<<Bpoint<<'\n';
   Apoint=0;
   Bpoint=0;
  }
 }
 return 0;
}