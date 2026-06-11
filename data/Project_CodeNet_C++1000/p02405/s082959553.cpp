#include<iostream>
using namespace std;

int main(){

int H,W;

while(1){

cin>>H>>W;

if(H==0&&W==0){break;}

for(int i=0;i<H;i++){

int write;

if(i%2==0){write=1;}else{write=0;}

for(int j=0;j<W;j++){

if(j%2==write){cout<<".";}else{cout<<"#";}

}

cout<<"\n";

}

cout<<"\n";

}

return 0;

}