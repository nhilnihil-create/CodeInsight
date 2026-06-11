#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#define inf 1e9+7
using namespace std;
typedef long long ll;
const double pi=acos(-1);

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> P(n);
    for(int i=0;i<n;i++) cin >> P[i];
    vector<double> cum(n);
    cum[0]=((double)P[0]+1)/2;
    for(int i=1;i<n;i++){
        cum[i]=cum[i-1]+((double)P[i]+1)/2;
    }
    double ans=cum[k-1];
    for(int i=k;i<n;i++){
        double tmp=cum[i]-cum[i-k];
        ans=max(ans,tmp);
    }
    printf("%.12f\n",ans);
}