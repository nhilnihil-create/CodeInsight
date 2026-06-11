#include<bits/stdc++.h>
using namespace std;
#define INIT  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define ll long long
#define pii pair<int, int>
#define count_bits __builtin_popcount
#define int ll

int t, n, m, k, a[300010], q, l, r;


int32_t main(){
INIT
cin>>n>>k;
for(int i=1; i<=n; i++){
    cin>>a[i];
}


int l=0, r=1e9;
while((l+1)<r ){
    int mid=(l+r)/2;
    int cnt=0;
    for(int i=1; i<=n; i++){
        if(a[i]%mid==0 ){
            cnt+=(a[i]/mid)-1;
        }
        else{
        cnt+=a[i]/mid;}
    }
    if(cnt<=k){r=mid;}
    else{l=mid;}
}
cout<<r;


return 0;
}



