#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,r;
    cin>>x;
    r=x/500;
    x=x%500;
    cout<<r*1000+(x/5)*5<<endl;
}
