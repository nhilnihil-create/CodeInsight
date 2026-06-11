#include<iostream>
using namespace std;
int main(){
int n,i,k,c=0;
cin>>n;
for(i=1;i<=n;i++){
    cin>>k;
    if(i%2!=0 && k%2!=0){
        c++;
    }

}
cout<<c<<endl;
return 0;}
