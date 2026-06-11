#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int N; cin >> N;
    vector<string> S;

    rep(i ,N){
        string s; cin >> s;
        S.push_back(s);
    }

    sort(S.begin(), S.end());

    int ans=1;
    string now=S[0];
    rep(i, N){
        if(S[i] != now){
            ans++;
            now=S[i];
        }
    }

    cout << ans << endl;
    return 0;
}