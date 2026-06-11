#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
 
const double PI = acos(-1);
 
int main(){
	int N,M;
    cin >> N >> M;
    int a,sum=0;
    rep(i,M) {
        cin >> a;
        sum+=a;
    }
    sum = N - sum;
    if(sum < 0) {
        cout << -1 << "\n";
    } else {
        cout << sum << "\n";
    }
    return 0;
}