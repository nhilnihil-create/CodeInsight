#include <bits/stdc++.h>
using namespace std;
int main ()
{
    long long int n,i,fact=1;
    cin>>n;
    while (n!=0)
    {
        fact*=n;
        n--;
    }
    cout<<fact<<endl;
}
