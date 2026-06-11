#include<iostream>
using namespace std;

int main(){
int buy,oturi,kouka;
while(1){
cin>>buy;
if(buy==0){
break;
}
oturi=1000-buy;
if(oturi>500){
oturi-=500;
kouka+=1;
}
while(oturi>=100){
oturi-=100;
kouka+=1;
}
while(oturi>=50){
oturi-=50;
kouka+=1;
}
while(oturi>=10){
oturi-=10;
kouka+=1;
}
while(oturi>=5){
oturi-=5;
kouka+=1;
}
while(oturi>=1){
oturi-=1;
kouka+=1;
}
cout<<kouka<<'\n';
kouka=0;
}

return 0;
}