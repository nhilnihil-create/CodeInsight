#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i=0;i<N;i++) cin >> A[i];
    sort(A.begin(),A.end());
    vector<int> plus;
    vector<int> minus;
    plus.push_back(A[N-1]);
    minus.push_back(A[0]);
    for (int i=1;i<N-1;i++){
        if (A[i] >= 0) plus.push_back(A[i]);
        else minus.push_back(A[i]);
    }
    vector<pair<int,int>> ans;
    for (int i=0;i<plus.size()-1;i++){
        int x, y;
        x = minus[minus.size()-1];
        y = plus[i];
        ans.emplace_back(x,y);
        minus[minus.size()-1] = x - y;
    }
    for (int i=0;i<minus.size();i++){
        int x, y;
        x = plus[plus.size()-1];
        y = minus[i];
        ans.emplace_back(x,y);
        plus[plus.size()-1] = x - y;
    }
    cout << plus[plus.size()-1] << "\n";
    for (int i=0;i<ans.size();i++){
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}