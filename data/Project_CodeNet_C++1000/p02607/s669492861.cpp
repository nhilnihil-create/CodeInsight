#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,c=0,x;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x&1&&i&1)
            c++;
    }
    cout<<c;
    return 0;
}
