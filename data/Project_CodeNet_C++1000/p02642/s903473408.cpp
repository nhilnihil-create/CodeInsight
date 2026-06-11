#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include<numeric>
using namespace std;
using P = pair<int, int>;
#define rep(i,n) for(int i=0; i<(n);i++)
typedef long long ll;

const int M = 1000005;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> cnt(M);
    sort(a.begin(), a.end());
    for(int x : a){
        if(cnt[x] != 0){
            cnt[x] = 2;
            continue;
        }
        for(int i=x; i < M; i += x) cnt[i]++;
    }
    int ans = 0;
    for(int x : a){
        if(cnt[x] == 1) ans++;
    }
    cout << ans << endl;
	return 0;
}
