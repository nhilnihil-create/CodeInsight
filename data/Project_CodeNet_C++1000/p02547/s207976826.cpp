#include <iostream>
#include<bits/stdc++.h> 
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a; int b;
    int temp =0;
    bool flag = false;
    for(int i =0; i<n; i++){
        if(temp ==3){
        cout<<"Yes"<<endl;
        flag = true;
        break;
        }
        cin>>a;
        cin>>b;
        if(a==b)
        temp++;
        else
        temp =0;
    }
    if(!flag){
   if(temp==3)
   cout<<"Yes"<<endl;
   else 
   cout<<"No"<<endl;
    }
   return 0;
}