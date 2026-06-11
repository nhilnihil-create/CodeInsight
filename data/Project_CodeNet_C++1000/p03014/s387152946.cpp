#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int h, w;   cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++)
        cin >> s[i];

    vector<vector<int> > a(h, vector<int>(w, 0)), b(h, vector<int>(w, 0)), c(h, vector<int>(w, 0)), d(h, vector<int>(w, 0));
    
    for (int i = 0; i < h; i++) {
        for (int j = 1; j < w; j++) {
            if (s[i][j-1] == '.')
                a[i][j] = a[i][j-1]+1;
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = w-2; j >= 0; j--) {
            if (s[i][j+1] == '.')
                b[i][j] = b[i][j+1] + 1;
        }
    }

    for (int i = 1; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i-1][j] == '.')
                c[i][j] = c[i-1][j] + 1;
        }
    }
    for (int i = h-2; i >= 0; i--) {
        for (int j = 0; j < w; j++) {
            if (s[i+1][j] == '.')
                d[i][j] = d[i+1][j] + 1;
        }
    }

    long long ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '.')
                ans = max(ans, (long long)(a[i][j]+b[i][j]+c[i][j]+d[i][j]+1));
        }
    }

    cout << ans << endl;

    return 0;
}