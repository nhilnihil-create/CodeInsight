#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> a(N+1);
    for (int i=1;i<=N;i++) cin >> a[i];
    vector<int> res(N+1);
    for (int i=N;i>=1;i--){
        int sum = 0;
        for (int x=2*i;x<=N;x+=i){
            sum += res[x];
            sum %= 2;
        }
        res[i] = a[i]^sum;
    }
    vector<int> ans;
    for (int i=1;i<=N;i++){
        if (res[i] == 1) ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for (int i=0;i<ans.size();i++){
        cout << ans[i] << "\n";
    }
}