#include <bits/stdc++.h>

using namespace std;

int a,j=1,i,N,sum=0;

int main()
{
    cin>>a;
    while(j<10){
    for(i=1;i<=9;i++){
    N=i*j;    
    if(a==N){
        sum=1;
    }
    }
    j++;
    }
    if(sum==1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}