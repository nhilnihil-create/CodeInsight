
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int sum=0;
    while(n>0)
    {
        n=(n/k);
        sum++;
    }
    cout<<sum;

}
