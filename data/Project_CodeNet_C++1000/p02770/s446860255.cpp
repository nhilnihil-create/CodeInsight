#include<bits/stdc++.h>

using namespace std;
#define taskname "A"
#define pb	push_back
#define mp  make_pair

typedef long double ld;
typedef long long ll;
typedef pair<int,int> ii;
const int maxn = 5000 + 5;
const int mod = 1e9 + 7;
int k , q , d[maxn];
int a[maxn];
int n , m , x;

void solve(){
    cin >> n >> x >> m;
    ll sum = 0;
    for(int i = 0 ; i < k ;  ++i){
        sum += (d[i] % m == 0 ? m : d[i] % m);
    }
    sum *= ((n - 1) / k);
    for(int i = 0 ; i < (n - 1) % k ; ++i){
        sum += (d[i] % m == 0 ? m : d[i] % m);
    }
    sum += x % m;
    cout << n - 1 - sum / m << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if(fopen(taskname".INP","r")){
        freopen(taskname".INP", "r",stdin) ,
        freopen(taskname".OUT", "w",stdout);
	}
    cin >> k >> q;
    for(int i = 0 ; i < k ; ++i){
        cin >> d[i];
    }
    while(q--)solve();
}
