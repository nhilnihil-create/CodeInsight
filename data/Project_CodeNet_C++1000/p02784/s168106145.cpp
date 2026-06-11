#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    long long int a,b,sum=0;
    cin>>a>>b;
    int c[b];
    for(int i=0;i<b;i++){
        cin>>c[i];
    }
    for(int i=0;i<b;i++){
        sum=sum+c[i];
    }
    int d=a-sum;
    if(d>0){
        cout<<"No\n";
    }
    else{
        cout<<"Yes\n";
    }
    return 0;
}
