#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,m,s ;
    cin >> a;
    m=a%1000;
    s=1000-m;
    if(m==0)
        s=0;
    cout<<s<<endl;
    return 0;
}
