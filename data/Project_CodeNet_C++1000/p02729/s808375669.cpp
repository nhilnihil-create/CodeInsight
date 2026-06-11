#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
#define aint(v) v.begin(),v.end()
#define endl "\n"
#define all(v) v.begin(),v.end()
#define clr(n, r) memset(n,r,sizeof(n))
typedef bitset<15> MASK;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

void fast() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main() {
    fast();
    int n,m;cin>>n>>m;
    cout<<(n*(n-1)/2)+(m*(m-1)/2);
}
