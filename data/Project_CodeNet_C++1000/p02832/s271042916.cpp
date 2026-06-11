#include <bits/stdc++.h>
using namespace std;
int n,f=1,sum,a[200001];
int main() 
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
        if (a[i]==f)
            f++;
		else
            sum++;
    if(f==1)
        cout<<-1;
    else
        cout<<sum;
}