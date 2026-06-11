#include <bits/stdc++.h>

using namespace std;

#define long long long
#define INF ((long) 2e18)
#define MOD ((long) (1e9 + 7))
#define umap unordered_map

int main()
{
    ios::sync_with_stdio(true); cin.tie(0); cout.tie(0);

    long t = 1;
    //cin >> t;

    while (t--) {
        string s;
        cin >> s;

        vector<string> week = {
            "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"
        };
        for (long i = 0; i < 7; i++) {
            if (week[i] == s) {
                long count = 1;
                for (long j = (i+1) % 7; week[j] != "SUN"; j = (j + 1) % 7) {
                    count++;
                }
                printf("%lld\n", count);
                return 0;
            }
        }
    }
}
