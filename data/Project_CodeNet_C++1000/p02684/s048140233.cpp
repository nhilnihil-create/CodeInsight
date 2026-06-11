#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl;
// *min_element(c + l, c + r) *max_element(c + l, c + r)
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// struct Edge {
//   int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };

int a[200020];

int main() {
    int n;
    ll k;
    cin>>n>>k;
    rep(i,n) {
        cin>>a[i];
        a[i]--;
    }
    map<int,int> ma;
    vector<int> ord;
    int now = 0,cnt=1;
    ma[0]=1;
    ord.push_back(0);
    int start,end;
    while(1) {
        if(ma[a[now]]) {
            start = ma[a[now]];
            end = cnt+1;
            break;
        } else {
            cnt++;
            ma[a[now]] = cnt;
            ord.push_back(a[now]);
            now = a[now];
        }
    }
    // for(auto n:ord) {
    //     cout<<n<<endl;
    // }
    if(k<start) {
        cout<<ord[k]+1<<endl;
    } else {
        int num = (k-start+1)%(end-start);
        // cout<<num<<" st "<<start<<" end "<<end<<endl;
        cout<<ord[start -1 + num]+1<<endl;
    }
}