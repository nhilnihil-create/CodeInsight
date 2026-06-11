#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;


int main(){
    fastio;
    int x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    vector<int> A;
    vector<int> B;
    vector<int> C;
    for(int i = 0; i<a; i++){
        int x;
        cin >> x;
        A.push_back(x);
    }
    for(int i = 0; i<b; i++){
        int x;
        cin >> x;
        B.push_back(x);
    }
    sort(all(A), greater<int>());
    sort(all(B), greater<int>());
    for(int i = 0; i<x; i++){
        C.push_back(A[i]);
    }
    for(int i = 0; i<y; i++){
        C.push_back(B[i]);
    }
    for(int i = 0; i<c; i++){
        int x;
        cin >> x;
        C.push_back(x);
    }
    ll ans = 0;
    sort(all(C), greater<int>());
    for(int i = 0; i<x+y; i++){
        ans += C[i];
    }
    cout << ans << endl;

}