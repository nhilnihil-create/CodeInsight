#include<iostream>
using namespace std;
int main(){
int h, w;
while(1){cin >> h >> w; 
if(h==0&&w==0)break;
for(int j=1; j<=h; j++){ 
if(j==1||j==h){
for(int i=1;i<=w;i++){
cout<<"#";
}
}else{
for(int i=1; i<=w; i++){
if(i==1||i==w){
cout<<"#";
}else{ 
cout<<".";
}
}
}cout<<"\n";
}cout<<"\n";
}
}