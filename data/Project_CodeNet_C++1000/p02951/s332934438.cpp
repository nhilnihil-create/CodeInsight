#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a,b,c,e,f;
    cin>>a>>b>>c;
    f=a-b;
    e=c-f;
    if(e<0)
        e=0;
    cout<<e;
}
