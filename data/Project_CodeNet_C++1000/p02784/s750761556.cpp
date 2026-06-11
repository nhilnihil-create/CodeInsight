#include <iostream>
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main()
{
    int h,n;
    cin>>h>>n;
    int a,s=0;
    rep(i,n) {cin>>a;s=s+a;}
    
    if(s>=h){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
   
   return 0;
}