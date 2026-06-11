#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,l;
    cin>>n>>l;
    if(n*2>l){
        cout<<"No\n";
        return 0;
    }
    int temp=l-2*n;
    if(temp%2!=0)
    {
        cout<<"No\n";
        return 0;
    }
    temp/=2;
    if(temp>n){
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    return 0;
}
