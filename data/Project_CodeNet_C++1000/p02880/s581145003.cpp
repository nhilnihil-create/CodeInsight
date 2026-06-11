#include<iostream>
using namespace std;
int main(){
int n,i,p=0;
cin>>n;
for(i=9;i>=1;i--){
    if(n%i==0){
        if((n/i)<=9){
            p=1;
            break;

        }
    }
}
if(p)cout<<"Yes"<<endl;
else cout<<"No"<<endl;
}
