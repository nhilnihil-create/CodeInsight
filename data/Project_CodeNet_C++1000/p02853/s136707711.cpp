#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>

#define LL long long
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define vecprint(vec) for (int i=0;i<vec.size();i++)printf("%d ",vec[i]);
#define all(x) x.begin(),x.end()
#define sc(x) scanf("%lld",&x)
#define scl(x) scanf("%lld",&x)
#define MEM(v,x) memset(v,x,sizeof v)

const double eps=1e-7,PI=3.1415926;
const int N=2e5+10;

using namespace std;

LL n,q,m,k,x,y,a[N],mx=-1,mn=1e9,sum,t;
char c[N];
string s,s1,s2;
map < LL , LL > mp;
vector < LL > vec;

int main(){
    sc(n),sc(m);
    a[1]=300000,a[2]=200000,a[3]=100000;a[0]=400000;
    if (n==1&&m==1)cout<<a[1]+a[1]+a[0]<<endl;
    else {
        cout<<a[n]+a[m]<<endl;
    }
    return 0;
}
