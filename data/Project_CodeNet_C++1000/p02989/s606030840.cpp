#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define reps(i,s,n) for (int i = (s); i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {

    int N;
    cin >> N;
    int d[N];
    for(int i = 0; i < N; i++){
        cin >> d[i];
    }

    sort(d, d+N);
    int l = d[(N-1)/2];
    int r = d[N/2];
    
    int ans = 0;
    if(l != r){
        for(int i = l+1; i <= r; i++){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}