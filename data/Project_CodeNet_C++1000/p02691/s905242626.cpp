#include <bits/stdc++.h>
using namespace std;
#define INF 1e9+7
typedef long long int ll;
const int maxn = 200000;
ll mod = INF;


int main(){

    int n;
    ll ans=0;
    ll a[maxn];
    map<ll,int> sum;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]>=n){continue;}
        sum[i+1+a[i]]++;
    }

    for(int i=0;i<n;i++){
        int temp=i+1-a[i];
        if(temp<2){continue;}
        ll num=sum[temp];
        ans+=num;
    }

    cout << ans<<endl;

    return 0;
}