#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include <set>
#define ll long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f3f
#define pi 3.1415926535898
using namespace std;

int main()
{
     int sum,a,c;
    cin>>sum>>a;
    for(int i=0;i<a;i++)
    {
        cin>>c;
        sum-=c;
    }
    if(sum<0)
    cout<<-1<<endl;
    else
    {
        cout<<sum<<endl;
    }
    return 0;
}
