#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
typedef signed long long ll;
#define FOR(i,to) for(i=0;i<(to);i++)

int64_t n; 

int main() {
	int i,j,k,l,r,x,y; string s;

    ll N;
    cin >> N;
    ll a[N];
    ll b[N];
    FOR(i,N) cin >> a[i] >> b[i];

    sort(a, a+N);
    sort(b, b+N);

    ll ans;
    if(N%2==0){
        if(N==2){
            ans = (b[0]-a[0]+1)+(b[1]-a[1]+1)-1;
            std::cout << ans << "\n";
        }else{
            ans = (b[N/2-1]-a[N/2-1]+1)+(b[N/2]-a[N/2]+1)-1;
            std::cout << ans << "\n";
        }
    }else{
        std::cout << b[(N+1)/2-1]-a[(N+1)/2-1]+1 << "\n";
    }
    return 0;
}
