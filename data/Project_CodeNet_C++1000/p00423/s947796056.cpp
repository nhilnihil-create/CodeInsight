#include<iostream>
using namespace std;
int main(){
    while(1){
         int n,aten=0,bten=0;
         cin>>n;
         if(n==0)break;
         for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            if(a>b){
              aten+=a+b;
              }
            else if(a==b){
                   aten+=a;
                   bten+=b;
            }
            else if(a<b){
                   bten+=a+b;
            }
         }
         cout<<aten<<" "<<bten<<endl;
    }
}
