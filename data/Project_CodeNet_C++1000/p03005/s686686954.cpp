#include <bits/stdc++.h>
using namespace std;

#define fRead  freopen("D:\\1805057\\in.txt","r",stdin)
#define fWrite freopen ("D:\\1805057\\out.txt","w",stdout)
#define FAST_READ ios_base::sync_with_stdio(0);cin.tie(0);

#define WATCH(a) cout << (a) << endl;
#define WATCH2(a, b) cout << (a) << " " << (b) << endl;
#define WATCH3(a, b, c) cout << (a) << " " << (b) << " " << (c) << endl;

#define MEM(a) memset(a, 0, sizeof(a))
#define PI acos(-1.0)

#define Equal(a, b) (abs(a-b)<1e-9)
#define WithIn(a, b, c) ((b)<=(a) && (a)<=(c))

#define getbit(n,i) (((n)&(1<<(i)))!=0)
#define setbit0(n,i) ((n)&(~(1<<(i))))
#define setbit1(n,i) ((n)|(1<<(i)))
#define togglebit(n,i) ((n)^(1<<(i)))

#define f first
#define s second
#define pb push_back

#define pii pair<int, int>;
#define vpi vector<pair<int, int> >;

#define SORT12(a) sort(a, a+sizeof(a)/sizeof(a[0]))
#define SORT21(a, type) sort(a, a+sizeof(a)/sizeof(a[0]), greater<type>())

#define amax(a, b) a=max(a, (b));
#define amin(a, b) a=min(a, (b));

/// bitset<size>

typedef long long int li;
typedef unsigned long long lu;

int main()
{
    //int T, CASE=0; cin >> T; while(T--){

    int n, k; cin >> n >> k;

    if(k==1) cout << 0 <<endl;
    else cout << n-k << endl;

    //}

	return 0;
}
