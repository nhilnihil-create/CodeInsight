
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int h1,m1,h2,m2,k,s=0;
    cin>>h1>>m1>>h2>>m2>>k;
    s=((h2*60+m2)-(h1*60+m1)-k);
    cout<<s<<endl;
}
