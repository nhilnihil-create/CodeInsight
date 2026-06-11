#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int h1,h2,m1,m2,k,i;
    cin>>h1>>m1>>h2>>m2>>k;
    if(h2>=h1)
    {
        i=(h2-h1)*60+m2-m1;
        if(i>=k)
            cout<<i-k;
        else
            cout<<"0";
    }
    else
    {
        i=(24-h1)*60-m1+h2*60+m2;
        if(i>=k)
            cout<<i-k;
        else
            cout<<"0";
    }



return 0;
}
