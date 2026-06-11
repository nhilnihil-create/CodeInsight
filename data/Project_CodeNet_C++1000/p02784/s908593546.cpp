#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, cnt=0, i, a;
    cin>>n>>m;
    for(i=1;i<=m;i++){
        cin>>a;
        cnt=cnt+a;
    }
    if(cnt>=n)
        cout<<"Yes";
    else
        cout<<"No";
}
