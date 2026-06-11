#include<iostream>
using namespace std;
int main(){
    int a,b,div,sum=0;
    cin>>a>>b;

    sum=a+b;

    if(sum%2==0){
        div=sum/2;
        cout<<div;
    }else{
        cout<<"IMPOSSIBLE";
    }


}
