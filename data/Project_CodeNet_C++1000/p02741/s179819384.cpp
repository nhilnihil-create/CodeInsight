#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define in insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Maxn 4000007
const int INF = 1e9 + 5;
const int  N = 2e5 + 314;
void foo(){
    int k;
    cin>>k;
    vi v{1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    cout<<v[k-1];
}
int main(){
    speed;
    int t=1;
    //cin>>t;
    while(t--)foo();
}