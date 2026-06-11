#include<bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define lld I64
#endif

#define endl '\n'
#define ii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define add push_back

int main(){ios_base::sync_with_stdio(false);

    int n, ma, mb;
    scanf("%d", &n);
    vi a(n), b(n);
    for(int i=0; i<n; ++i) scanf("%d %d", &a[i], &b[i]);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    if(n&1){
        ma = a[n/2];
        mb = b[n/2];
    }else{
        ma = a[n/2-1] + a[n/2];
        mb = b[n/2-1] + b[n/2];
    }

    printf("%d\n", mb-ma+1);

    return 0;
}
