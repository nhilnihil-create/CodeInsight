#include <bits/stdc++.h>

using namespace std;

int main()
{
    int l,r,k;
    cin>>k>>l>>r;
    l = (l/k+(l%k!=0))*k;
    if(l>r)
    {
        cout<<"NG"<<"\n";
    }
    else
        cout<<"OK";
    return 0;
}
