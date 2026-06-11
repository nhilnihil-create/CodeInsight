#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int idx=1,cnt=0;
    while(n--)
    {
        int a;
        cin>>a;
        if(a%2==1&&idx%2==1)cnt++;
        idx++;
    }
    cout<<cnt<<endl;
}
