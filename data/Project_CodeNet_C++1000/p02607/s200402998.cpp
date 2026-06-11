#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,out=0,in;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>in;
        if((i%2!=0)&&(in%2!=0))
            out++;
    }
    cout<<out<<endl;
    return 0;
}