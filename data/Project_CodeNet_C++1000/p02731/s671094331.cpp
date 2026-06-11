#include<bits/stdc++.h>
#define ll long long
#define MAX 1000000000
#define INF 1000000 
#define M 1000000007
#define PI 2 * acos(0.0)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main(){
    fast_io 
    long double n;
    cin>>n;
    long double r = pow(n,3);
    long double ans = r/27;
    cout<<fixed<<setprecision(12)<<ans<<endl;
    return 0;
}
