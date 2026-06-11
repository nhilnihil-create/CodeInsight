#include<bits/stdc++.h>
#include<string.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define see(x) cout<<#x<<" : "<<(x)<<endl;
#define ya cout<<"yes"<<endl;
#define no cout<<"no"<<endl;
#define ff first
#define sc second
typedef unsigned long long ll;
using namespace std;
int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(NULL),cout.tie(NULL);
    long double w,h,x,y,a,b,ans=0;
    cin>>w>>h>>a>>b;
    ans=(w*h);
    ans/=2;
    int p=0;
    if(a==(w/2) && b==(h/2.0))p=1;
    printf("%.6LF %d\n",ans,p);
    return 0;
}