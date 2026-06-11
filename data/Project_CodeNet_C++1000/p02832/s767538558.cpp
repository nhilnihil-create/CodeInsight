#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int ans = -1;
    int j = 1;
    int last = -1;
    for (int i = 0; i < N; i++)
    {
        if (A[i] == j)
        {
            ans = i + 1 - j;
            j++;
            last = i;
            continue;
        }
        if (i == N - 1 && j > 1)
        {
            ans += (i - last);
        }
        
    }
    
    cout << ans << endl;

  return 0;
}
