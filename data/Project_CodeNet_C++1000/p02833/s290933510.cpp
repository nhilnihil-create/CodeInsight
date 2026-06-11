#include<iostream>
using namespace std;

int main(){
    long long n;
    cin>>n;
    if(n%2==1){
        cout<<0<<endl;
        return 0;
    } 
    long long five=10;
    long long res=0;
    while(n>=five){
        res+=n/five;
        five*=5;
    }

    cout<<res<<endl;
}