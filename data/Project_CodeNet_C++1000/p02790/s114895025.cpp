#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    if(x>y){
        for(int i=0;i<x;i++)
            cout<<y;
    }
    else{
        for(int i=0;i<y;i++)
            cout<<x;
    }
}
