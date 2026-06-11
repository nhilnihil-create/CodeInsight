#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
#define dd double
#define oo 1001007000
#define ff float
#define ooo 4223352036854775007
#define iii pair<ll,ll>
#define vii vector<ll>
#define viii vector<iii>
#define sss pair<str,str>
#define str string
#define sii set<ll>
#define siii set<iii>
#define r0 return 0
#define pb push_back
#define sz size
using namespace std;

const char E='\n';
const int N=200005;
const int NN=2005;
const ll md=998244353;



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ll a[N]={0};
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    ll ans=a[1];
    int k=n-2;
    for (int i=2;i<=n;i++){
        if (k==0)break;
        if (k>0){ans+=a[i];k--;}
        if (k>0){ans+=a[i];k--;}

    }
    cout << ans << E;
    return 0;
}


/*







*/
