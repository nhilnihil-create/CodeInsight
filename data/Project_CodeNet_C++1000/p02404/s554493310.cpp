#include<iostream>
using namespace std;

int main(){

int H,W,i,j,p,q;

while(1){

cin>>H>>W;

if (H==0&&W==0)break;

for(p=0;p<W;p++){

cout<<"#";

}

cout<<"\n";

for(i=0;i<H-2;i++){

cout<<"#";

for(j=0;j<W-2;j++){

cout<<".";

}

if(W!=1)cout<<"#";

cout<<"\n";

}


if(H!=1)for(p=0;p<W;p++){

cout<<"#";

}

if(H!=1)cout<<"\n";
cout<<"\n";

}

return 0;

}