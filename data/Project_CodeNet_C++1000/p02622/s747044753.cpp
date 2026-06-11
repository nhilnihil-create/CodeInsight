#include<bits/stdc++.h>
#include<algorithm>
#include<functional>
#define len(a) sizeof(a)/sizeof(a[0])
#define sort_asc(a,b) sort(a,a+b)
#define sort_dsc(a,b,dataType) sort(a,a+b,greater<dataType>())
#define IN cin>>
#define OUT cout<<
#define PI 3.14159265358979323846D
#define forr(i,b,e) for(int (i)=(b); (i) <= (e); (i)++)
#define pb push_back
#define mset0(x) memset((x), 0, sizeof((x)));
#define mset1(x) memset((x), -1, sizeof((x)));
#define vi vector<int>
#define nl endl
typedef long long int ll;
using namespace std;
void f();
int main()
{
    int t=1;
    //IN t;
    for(int i=0;i<t;++i) {f(); if(i!=t-1) OUT endl; else continue;}
    //{OUT "Case "<<i<<":"<<f(); if(i!=t-1) OUT endl; else continue;}
    return 0;
}
void f()
{
   string s1,s2;
   int cnt=0;
   IN s1>>s2;
   forr(i,0,s1.length()-1)
        if(s2[i]==s1[i]) continue;
        else ++cnt;
    OUT cnt;
}
