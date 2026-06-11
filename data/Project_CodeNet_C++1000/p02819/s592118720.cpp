#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

bool isPrime(int x){
    bool flag=true;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) flag=false;
    }
    if(flag)return true;
    else return false;
}

int main(){
    int x;
    cin>>x;
    for(int i=x;i<=200000;i++){
        if(isPrime(i)){
            cout<<i<<endl;
            return 0;
        }
    }
}