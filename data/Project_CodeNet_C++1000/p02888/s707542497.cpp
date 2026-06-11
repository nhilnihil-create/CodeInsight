#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin >>n;
    vector<int> edge(n);
    for(int i=0; i<n; i++) cin >> edge[i];
    sort(edge.begin(), edge.end());
    int ans = 0;

    for(int i=n-1; i>=0; i--){
        for(int j=i-1; j>=0; j--){
            auto iter = lower_bound(edge.begin(), edge.end(), edge[i]+edge[j]);
            ans += n-1-i - (edge.end()-iter);
        }
    }
    cout << ans << endl;
}