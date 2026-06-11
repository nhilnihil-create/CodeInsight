#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <queue>
#include <map>
using namespace std;

#define mod 1000000007
#define ten5 100005
#define ten6 1000005
#define PI 3.1415926

typedef long long int ll;

int x[55],y[55];
//int num[ten6];

int main()
{
    //int m,n,o=0,i,j,k;
    long long int sum=0,sum2=0,n1=0,n2=0,n3;
    double ans=0.0,half;
    long long int m,n,o,i,j,k=1,now=1;
    long long int a,a1,a2,a3,a4,a5,a6;
    a=a1=a2=a3=a4=a5=a6=0;
    //float f,g,h;
    char c;
    string s,s1;
    //priority_queue<long l ong int> pq;
    vector<pair<ll,ll>> vint;
    map<pair<ll,ll>,ll> mp;
    //list<int> li;
    //map<string,int>::iterator iter;
    //set<int> sint;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a1>>a2;
        x[i]=a1;y[i]=a2;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j) continue;
            a1=x[i]-x[j];a2=y[i]-y[j];
            mp[make_pair(a1,a2)]++;
        }
    }
    for(auto au:mp)
    {
        sum=max(sum,au.second);
    }
    cout<<n-sum;
    return 0;
}

