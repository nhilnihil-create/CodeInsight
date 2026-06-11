#include<iostream>
using namespace std;
int zyo[4][3][10]={0},mune,kai,hidari,n,hito;
int in(){
cin>>n;
for(int a=0;a<n;a++){
cin>>mune>>kai>>hidari;
cin>>hito;
zyo[mune-1][kai-1][hidari-1]+=hito;
}
}
int out(){
for(int a=0;a<4;a++){
for(int b=0;b<3;b++){
for(int c=0;c<10;c++){
cout<<" "<<zyo[a][b][c];
}
cout<<endl;
}
if(a<3)
cout<<"####################"<<endl;
}
}
int main(){
in();
out();
return 0;
}