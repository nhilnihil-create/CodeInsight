#include<iostream>
#include<string>
using namespace std;

int main(){
int a[1000000],b[1000000],c;
for(int i=1;i<1000000;i++){
cin>>a[i]>>b[i];
c++;
if(a[i]==0 && b[i]==0){
goto aa;
}
}
aa:;
for(int i=1;i<c;i++){
for(int j=0;j<a[i];j++){
for(int k=0;k<b[i];k++){
cout<<"#";
}
cout<<endl;
}
cout<<endl;
}
return 0;
}