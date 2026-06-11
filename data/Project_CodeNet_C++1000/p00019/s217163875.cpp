#include<cstdio>
#include<iostream>

using namespace std;

int main(){
    long long k=1;
    for(int i=1;i<=20;i++){
        k*=i;
    }
    cout<<k<<endl;
        return 0;
}