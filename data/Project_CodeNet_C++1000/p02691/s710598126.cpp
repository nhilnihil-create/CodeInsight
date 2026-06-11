#include<bits/stdc++.h>
#include<time.h>
#include<cctype>
#include<iostream>
#include<ostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;//1061109567
const int INF=0x7fffffff;//2147483647
const int SUP=0x80000000;//-2147483648
#define MAX 1000000
ll a[MAX]={0},b[MAX]={0};
int main()
{
    int n;
    int t;
    ll sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        if(i+t<=n)a[i+t]++;
        if(i-t>=1)b[i-t]++;
    }
    for(int i=1;i<=n;i++)
    {
        sum+=a[i]*b[i];
    }
    cout<<sum;
    return 0;
}
