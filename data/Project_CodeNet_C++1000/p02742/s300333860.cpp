#include<bits/stdc++.h>
 
#define lli long long int
#define endl "\n"
 
using namespace std;
 
typedef long long int LLI;
typedef double DB;
 
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}
 
 
bool comparator(pair<lli,lli> a,pair<lli,lli> b)
{
    if(a.first>b.first)
        return true;
    else if (a.first==b.second)
    {
        if(a.second>=b.second)
            return false;
        return true;
    }
    return false;
}
 
int mods(int x)
{
    if(x>0)
        return x;
    return -x;
}
 
lli gcd(lli a,lli b)
{
    return __gcd(a,b);
}
 
lli lcm(lli x,lli y,lli z)
{
    lli j=gcd(x,y);
    lli k=gcd(y*x/j,z);
    return (((x*y)/j)*z)/k;
} 
 
int main()
{
    fastio();
    lli h,w; cin>>h>>w;
    if(h==1 || w==1) {cout<<1<<endl; return 0;}
    cout<<((w+1)/2)*((h+1)/2)+(w/2)*(h/2);
    return 0;
}