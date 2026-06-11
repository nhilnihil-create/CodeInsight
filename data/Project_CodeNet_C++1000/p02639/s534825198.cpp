#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[5];
    for(int i=0;i<5;i++)
     cin>>a[i];
    int ind=0;
    for(int i=0;i<5;i++)
    {
        if(a[i]==0)
         ind=i+1;
    }
    cout<<ind<<endl;
    return 0;
}