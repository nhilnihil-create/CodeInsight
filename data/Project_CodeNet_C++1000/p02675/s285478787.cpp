#include<iostream>
#include<cmath>
using namespace std;
int main(){
int N;
cin>>N;
if(N>0 && N<=999){
int k=N%10;
if(k==2 ||k==4 || k==5 ||  k==7 || k==9){
cout<<"hon";
} 
else if(k==0 || k==1 || k==6 || k==8){
cout<<"pon";
}
else{
cout<<"bon";
}

}  
 
 
return 0;
}