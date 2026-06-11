#include<bits/stdc++.h>

using namespace std;

int main(void)

{
    double r, c, a, b;
    cin>>r>>c>>a;
    if(r > c)b = ceil(a/r);
    else b = ceil(a/c);
    cout<<b<<endl;
    return 0;
}
