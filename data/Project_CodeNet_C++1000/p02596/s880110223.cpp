#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stdlib.h>
#include<stack>
using namespace std;
#define PI 3.14159265358979
typedef  long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#include<set>
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(void)
{
ll k;
cin>>k;

ll bfrmod = 0;

for(int i =0;i<=k;++i)
{
    ll now = 7*modpow(10,i,k);
    ll modnow = now%k;

    bfrmod = (modnow+bfrmod);
    bfrmod %=k;

    if(bfrmod==0) 
    {
        cout<<i+1<<endl;
        return 0;
    }



}
    cout<<-1<<endl;


}