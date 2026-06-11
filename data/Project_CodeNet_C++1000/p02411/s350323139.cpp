#include<iostream>
using namespace std;
int t,k,s;
int out(){
while(1){
cin>>t>>k>>s;
if(t==-1&&k==-1&&s==-1)
break;
if(t==-1||k==-1)
cout<<"F"<<endl;
else if(t+k>=80)
cout<<"A"<<endl;
else if(t+k>=65)
cout<<"B"<<endl;
else if(t+k>=50)
cout<<"C"<<endl;
else if(t+k>=30){
if(s>=50)
cout<<"C"<<endl;
else 
cout<<"D"<<endl;
}
else
cout<<"F"<<endl;
}
}
int main(){
out();
return 0;
}