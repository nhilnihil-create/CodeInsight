
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    map<int,int>Map;
    int X = 0;
    int ans = 0;
    int cnt = 1;
    Map[0] = 1;
    for(int i = S.size()-1; i >= 0; i--) {
        X = (X+(S[i]-'0')*cnt)%2019;
        ans+=Map[X];
        Map[X]++;
        cnt = (cnt*10)%2019;
    }
    cout << ans << endl;
}