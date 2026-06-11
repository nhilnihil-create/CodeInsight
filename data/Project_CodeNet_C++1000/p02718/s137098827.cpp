#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m; cin >> n >> m;
    int a[n];
    int sum = 0;

    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
    }

    sort(a, a+n);
    reverse(a, a+n);

    int req = sum/(4*m);

    if(a[m-1]*4*m>=sum) cout << "Yes\n";
    else cout << "No\n";



    

}
