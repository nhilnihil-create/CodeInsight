#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string S;
    map<string, int> mp;
    int maxCount = 0;
    for (int i = 0; i < N; i++) {
        cin >> S;
        mp[S]++;
        maxCount = max(maxCount, mp[S]);
    }
    for (auto i = mp.begin(); i != mp.end(); i++) {
        if (maxCount == i->second) {
            cout << i->first << endl;
        }
    }
    return 0;
}