#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;

int main(void){
    ll N,M,K;
    cin >> N >> M >> K;
    vector<int> a(N),b(M);
    REP(i,N)
        cin >> a[i];
    REP(i,M)
        cin >> b[i];

    ll sum=0;
    REP(i,M) sum+=b[i];

    int j=M;
    int ans=0;
    REP(i,N+1){
        while(j>0 && sum>K){
            --j;
            sum-=b[j];
        }
        if(sum>K) 
            break;
        ans=max(ans,i+j);
        if(i==N)
            break;
        sum+=a[i];
    }

    cout << ans << endl;

    return 0;
}