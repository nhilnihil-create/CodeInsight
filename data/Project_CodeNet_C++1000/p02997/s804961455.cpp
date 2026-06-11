#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define snd second
#define ALL(s) s.begin(),s.end()
#define fill(a,c) memset(&a, c, sizeof(a))
#define fore(i,x,y) for(ll i=x;i<y;i++)
#define SZ(x) ((int)(x).size())
#define PI 3.1415926535897932384626433832795
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
using namespace std;

int main() {FIN;
    int n,k; cin>>n>>k;
    int m = (n-1)*(n-2)/2;
    if(k > m){
        cout<<"-1\n"; return 0;
    }
    cout<<n-1+m-k<<"\n";
    fore(i,2,n+1) cout<<1<<" "<<i<<"\n";
    int cnt = 0;
    fore(i,2,n+1){
        fore(j,i+1,n+1){
            if(cnt == m-k) break;
            cout<<i<<" "<<j<<"\n";
            cnt++;
        }
        if(cnt == m-k) break;
    }
    return 0;
}

