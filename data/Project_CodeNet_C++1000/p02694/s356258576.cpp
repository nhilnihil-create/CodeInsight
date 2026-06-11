#include<bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long int x,count=0;
    cin>>x;
     unsigned long long int n=100;
    while(n<x)
    {
        n=n+n/100;
        count++;
    }
    cout<<count<<endl;
}