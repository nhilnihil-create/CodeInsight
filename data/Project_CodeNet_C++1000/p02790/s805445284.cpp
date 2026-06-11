#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,i;
    cin>>a>>b;
    if(a==b){
        for(i=0;i<a;i++)
            cout<<a;
        cout<<endl;
    }
    else if(a>b){
        for(i=0;i<a;i++)
            cout<<b;
        cout<<endl;
    }
    else{
        for(i=0;i<b;i++)
            cout<<a;
        cout<<endl;
    }
}
