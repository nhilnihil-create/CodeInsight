#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n>82)cout<<"No"<<endl;
    else{
        int flag=0;
        for(int i=1;i<=9;i++){
            if(n%i==0&&n/i<10)flag=1;
        }
        if(flag==1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}