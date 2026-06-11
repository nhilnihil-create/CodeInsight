#include<iostream>
using namespace std;

int main(){
int H[100000],W[100000];
int c=0;
for(int i=1;i<100000;i++){
cin>>H[i]>>W[i];
c++;
if(H[i]==0 && W[i]==0){
goto aa;
}
}
aa:;
for(int i=1;i<c;i++){
for(int j=0;j<H[i];j++){
for(int k=0;k<W[i];k++){
    if((j+k)%2==0){
    cout<<"#";
    }
    else{
    cout<<".";
    }
}
cout<<endl;
}
cout<<endl;
}
return 0;
}