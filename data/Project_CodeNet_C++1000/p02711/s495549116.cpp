#include <iostream>
using namespace std;
int main(){
int x;
cin>>x;
int z=0;
for(int i=0 ;i<=2;i++){
if(x%10==7){
cout<<"Yes"<<endl;
z++;
break;
}
else{
    x/=10;
}}
if(z==0)
    cout<<"No";
return 0;
}
