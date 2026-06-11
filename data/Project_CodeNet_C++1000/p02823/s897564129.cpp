#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<vector<int>> Graph;

int main() {
    ll n,a,b;
    cin >> n >> a >> b;
    if(a%2==b%2){
        cout << (b-a)/2 << endl;
    } else {
        cout << min(a-1,n-b) + 1 + (b-a-1)/2 << endl;
    }
}