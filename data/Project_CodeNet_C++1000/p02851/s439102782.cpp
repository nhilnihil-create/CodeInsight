#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
// 10 7
// 14+15+92+65+35+89+79+32+38+46
    int n, k;
    cin >> n >> k;
    vector<int> int_seq(n);
    rep(i, n){cin >> int_seq.at(i);}
    rep(i, n){int_seq[i]--;}
    vector<int> cumulative_sum(n+1);
    for (int i = 0; i < (n); ++i){
        cumulative_sum[i+1] = (cumulative_sum[i] + int_seq[i]) % k;
        // printf("cum_sum %d\n", cumulative_sum[i]);
    }
    map<int, int> cntr;
    long long ans = 0;
    queue<int> q;
    for (int i = 0; i < (n+1); ++i){
        ans += cntr[cumulative_sum[i]];
        cntr[cumulative_sum[i]]++;
        q.push(cumulative_sum[i]);
        if (q.size() == k){
            cntr[q.front()]--;
            q.pop();
        }
    }
    cout << ans << endl;
    return 0;
}