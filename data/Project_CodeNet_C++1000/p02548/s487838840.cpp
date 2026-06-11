#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
int main()
{
    optimize();
    int i,j;
    int n;
    cin>>n;
    long long sum=0;
    for(i=1;i<=n-1;i++)
    {
        sum+=(n-1)/i;
    }
    cout<<sum<<endl;
}
