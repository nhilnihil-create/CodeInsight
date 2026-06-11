#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int k,a=100,b=0,j,l,i;
    cin>>k;
    while(a<k)
    {
        a=a+(a/100);
        b++;
    }
    cout<<b<<endl;

}

