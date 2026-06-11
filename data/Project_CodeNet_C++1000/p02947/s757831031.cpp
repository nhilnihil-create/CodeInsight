#include<bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    map <string, long long> cnt;
    map <string, long long> S;
    cin >> N;
    for (long long i=0; i<N; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        S[s]+=cnt[s];
        cnt[s]+=1;
    }
    long long ans=0;
    for (auto i=S.begin(); i!=S.end(); i++) {
        ans += i->second;
    }
    cout << ans;
}