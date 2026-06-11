#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int x,count=0;
    cin>>x;
    int y[x];
    for(int i=0;i<x;i++){
        cin>>y[i];
    }
    for(int i=1;i<x-1;i++){
        if( (y[i]<y[i-1] && y[i]>y[i+1]) || (y[i]>y[i-1] && y[i]<y[i+1]) ){
            count++;
        }
    }
    cout<<count<<endl;

}

