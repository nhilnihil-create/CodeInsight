/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define EPS 1e-9
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}

int main()
{
    int n;
    cin>>n;
    int a[n+1],b[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    bool check=false;
    for(int i=1;i<=n-2;i++){
        if(a[i]==b[i] && a[i+1]==b[i+1] && a[i+2]==b[i+2]){
            check=true; break;
        }
    }
    if(check) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}


