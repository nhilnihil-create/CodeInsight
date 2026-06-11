#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h,w,k;
    cin>>h>>w>>k;
    vector<string> s(h);
    vector<int> row(h, 0);
    vector<int> col(w, 0);
    int sum = 0;
    for (int i=0; i<h; i++) {
        cin>>s[i];
        for (int j = 0; j<w; j++) {
            if (s[i][j] == '#') {
                row[i]++; col[j]++;
                sum++;
            }
        }
    }
    if (sum < k) {
        cout << 0 << '\n';
        return 0;
    }
    int res = 0;
    //cout << sum << '\n';
    for (int i = 0; i<(1<<h); i++) {
        int rem = sum;
        for (int j = 0; j<h; j++) {
            if (i & (1 << j)) rem -= row[j];
        }
        if (rem < k) continue;
        for (int j=0; j<(1<<w); j++) {
            int rem1 = rem;
            for (int j1 = 0; j1 < w; j1++) {
                if (j & (1 << j1)) {
                    rem1 -= col[j1];
                    
                }
            }
            for (int i1 = 0; i1 < h; i1++) {
                for (int j1 = 0; j1 < w; j1++) {
                    if ((i & (1<<i1)) && (j & (1<<j1)) && s[i1][j1] == '#') rem1++;
                }
            }
            if (rem1 == k) res++;
        }
    }
    cout << res << '\n';
    return 0;
}