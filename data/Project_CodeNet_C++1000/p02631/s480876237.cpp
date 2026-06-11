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
int main(void)
{
    ll b=0;
    ll n;
    cin>>n;
    vector<ll> a(n+3);
    rep(i,n)
    {   
        cin>>a[i];
        b = b^a[i];
    }


    rep(i,n)
    {
        cout<<(b^a[i])<<' ';
    }

        cout<<endl;
}
