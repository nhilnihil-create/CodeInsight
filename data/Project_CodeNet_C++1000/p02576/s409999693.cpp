#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define all(x) x.begin(), x.end()
#define watch(x) cout<<#x<<" : "<<x<<endl
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define testCases int tt;cin>>tt; while(tt--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<string> vs;

int main() {
    fastio;
    int n,x,t;
    cin >> n >> x >> t;
    if (n%x) {
        cout << ((n/x)+1)*t << endl;
    } else {
        cout << (n*t)/x << endl;
    }
    return 0;
}