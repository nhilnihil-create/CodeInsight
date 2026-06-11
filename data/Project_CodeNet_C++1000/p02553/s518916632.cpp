#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)
#define MOD 1000000007
#define deb(n) cout<<"[ "#n<<" = "<<n<<" ]"<<endl;
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const long long  MAX = 1 << 18;
int case_no = 1;
#define w(x) int x; cin>>x; while(x--)

int main() {
    FIO
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long ans;
    ans = max(max(a * c, a * d), max(b * c, b * d));
    cout << ans << endl;

    return 0;
}