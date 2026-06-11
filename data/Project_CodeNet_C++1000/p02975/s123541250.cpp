#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,h,sum=0;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>h;
        sum=sum^h;
    }
    if(sum==0){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

   return 0;
}
