#include<iostream>
using namespace std;
int main(){
int siharai=1;
int oturi;
int a;

while(siharai!=0){
cin>>siharai;
oturi=0;
if(siharai==0)
break;

oturi=1000-siharai;

if(oturi>500){
a+=1;
oturi-=500;
}


while(oturi>=100){

a+=1;
oturi-=100;


}

while(oturi>=50){

a+=1;
oturi-=50;


}

while(oturi>=10){

a+=1;
oturi-=10;


}

while(oturi>=5){

a+=1;
oturi-=5;

}

while(oturi>=1){

a+=1;
oturi-=1;


}
cout<<a<<'\n';
a=0;
}

return 0;

}