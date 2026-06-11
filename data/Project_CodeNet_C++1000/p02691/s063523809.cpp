#include<iostream>
#include<map>
using namespace std;
map<int,int> f;
int n;
int a[200005];
long long tot;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i-a[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        tot+=f[i+a[i]];
    }
    cout<<tot;
    return 0;
}
