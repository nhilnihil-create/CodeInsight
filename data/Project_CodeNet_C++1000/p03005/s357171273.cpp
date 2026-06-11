#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    if(k==1)
    {
        cout<<"0"<<endl;
        return 0;
    }
    int tmp = n - k;
    cout<<tmp<<endl;
    return 0;
}
