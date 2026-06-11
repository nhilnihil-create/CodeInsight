#include<iostream>
using namespace std;
int x[30],i,a;
int main(){
for(i=0;i<28;i++){cin>>a;x[a]=1;}
for(i=1;i<31;i++){if(x[i]==0){cout<<i<<endl;}}
}