#include<iostream>
#include <cmath>
using namespace std;
int main()
{
long long int c,a,b,i;
cin>>a>>b;

for(i=0;i<1000000000;i++){
    if((abs(a-i))==(abs(b-i))){
        c++;
        break;
    }
    else{
        c=0;
    }
}
if(c==1){
    cout<<""<<i<<endl;
}
else{cout<<"IMPOSSIBLE"<<endl;}



}
