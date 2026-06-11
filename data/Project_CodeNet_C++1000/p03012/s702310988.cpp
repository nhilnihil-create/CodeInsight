#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int arr[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,mn=INT_MAX;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    for(int i=1; i<=n; i++)
    {
        int x=0,y=0;
        for(int j=1; j<=i; j++)
            x+=arr[j];
        for(int j=i+1; j<=n; j++)
            y+=arr[j];
        int z=abs(x-y);
        mn=min(mn,z);
    }
    cout<<mn<<endl;



    return 0;
}
