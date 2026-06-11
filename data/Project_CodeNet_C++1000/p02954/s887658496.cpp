#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    string S;
    cin >> S;
    int n = S.size();
    vector<int> ans(n);
    for (int i=0; i<2; i++) {
        int cnt = 0;
        for (int i=0; i <n; i++) {
            if (S[i]=='R') {
                cnt++;
            } else {
                ans[i] += cnt/2;
                ans[i-1] += (cnt+1)/2;
                cnt = 0;
            }
        }
        reverse(ans.begin(), ans.end());
        reverse(S.begin(), S.end());
        for(int i=0; i<n; i++) {
            if (S[i]=='L') {
                S[i] = 'R';
            } else {
                S[i] = 'L';
            }
        }
    }
    for (int i=0; i<n; i++) {
        if (i==n-1) {
            cout << ans[i] << endl;
        } else {
            cout << ans[i] << " "; 
        }
    } 
    return 0;
}