#include <bits/stdc++.h>
 
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> P;
 
constexpr int INF = 1e9;
constexpr int MOD = 1e9+7;

int main() {
    int n;
    string c;
    cin >> n >> c;
    int l = 0,r = n-1,cnt = 0;
    while(l < r){
        while(l < n && c[l]!='W') l++;
        while(r >= 0 && c[r]!='R') r--;
        if(l>=r) break;
        cnt++;
        l++,r--;
    }
    cout << cnt << endl;

	return 0;
}