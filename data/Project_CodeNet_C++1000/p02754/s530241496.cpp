#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n,a,b;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    cin >> n >> a >> b;
    LL k = n%(a+b);
    LL ans = 0;
    ans += ((n-k)/(a+b))*a;
    ans += min(k, a);
    cout << ans;


    cout.flush();
    return 0;
}