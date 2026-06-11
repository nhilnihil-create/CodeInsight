#include<bits/stdc++.h>
using namespace std;
int main()
{
    typedef long long ll;
    ll a,b,k,l,m;
    cin>> a>> b>> k;
    if((a+b)<k)
    {
        cout<< "0 0"<< endl;
    }
    else if(k>=a)
    {
        l=k-a;
        m=b-l;
        cout<< "0 "<< m;
    }
    else
    {
        l= a-k;
        cout<< l<< " "<< b;
    }
}
