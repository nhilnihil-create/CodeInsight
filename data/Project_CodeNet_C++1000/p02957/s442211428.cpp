//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    if(a%2==b%2)
    {
        cout<<(a+b)/2<<endl;
    }
    else
        cout<<"IMPOSSIBLE"<<endl;


}


