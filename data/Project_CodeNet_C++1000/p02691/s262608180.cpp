#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<string>
#define ll long long
const int N=2e5+10;
using namespace std;
//const int f[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};                         //26个字母对应的数字
ll p[N];
map<ll,ll>m;
//p[i]+p[j]==j-i;(j>=i)
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        m[i-p[i]]++;
    }
    ll sum=0;
    for(int i=1;i<=n;i++)
        sum+=m[i+p[i]];
    cout<<sum<<endl;
    return 0;
}
