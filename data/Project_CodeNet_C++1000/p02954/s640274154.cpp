#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    string S; cin >> S;
    int N = S.size();
    vector<int> ans(N);
    char now = 'R';
    int st1 = 0, st2 = 1;
    int left, right;
    for (int i = 1; i < N; i++){
        if (S[i] == 'R'){
            if (i%2 == 0){
                st2++;
            } else {
                st1++;
            }
            now = S[i];
        } else {
            if (now == 'R'){
                right = i-1;
                left = i;
                ans[i-1]++;
                ans[i]++;
                if (i%2 == 0){
                    ans[i] += st2;
                    ans[i-1] += st1-1;
                    st1 = 0;
                    st2 = 0;
                } else {
                    ans[i] += st1;
                    ans[i-1] += st2-1;
                    st1 = 0;
                    st2 = 0;
                }
            } else {
                if (i%2 == left%2){
                    ans[left]++;
                } else {
                    ans[right]++;
                }
            }
            now = S[i];
        }
    }

    rep(i, N){
        cout << ans[i];
        if (i != N-1){
            cout << " ";
        } else {
            cout << endl;
        }
    }
    return 0;
}