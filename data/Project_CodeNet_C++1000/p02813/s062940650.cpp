#include <iostream>
#include <algorithm>
using namespace std;

#include <cmath>    //floor ceil
#include <cstdlib>  //abs
#include <cstdio>
#include <climits>  //INT_MAX
#include <cstring>
#define endl "\n"
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define lli long long int
#define MOD 1000000007
#include <map>
#define mp make_pair
#define mii map<int,int>
/*---------------------------------------------------CODE STARTS FROM HERE---------------------------------------------------*/
lli fact (int n) {
    if(n<=1) return 1;
    else {
        lli f=1;
        for (int i=2;i<n+1;i++) {
            f *= i;
        }
        return f;
    }
}
int main ()
{
    /*int tt;
    cin >> tt;
    while(tt--)
    {

    }*/
    lli ans=0,an=0;
    int n;
    cin >> n;
    int a[n],b[n];
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> b[i];

    for (int i=0;i+1<n;i++) {
        int c=0;
        for (int j=i+1;j<n;j++) {
            if(a[j]<a[i]) c++;
        }
        ans += c*fact(n-1-i);
    }
    for (int i=0;i+1<n;i++) {
        int c=0;
        for (int j=i+1;j<n;j++) {
            if(b[j]<b[i]) c++;
        }
        an += c*fact(n-1-i);
    }
    cout<<abs(ans-an)<<endl;
    return 0;
}