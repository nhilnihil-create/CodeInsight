#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<int> Zalgo(const string &S){
    int N = (int)S.size();
    vector<int> res(N);
    res[0] = N;
    int i = 1, j = 0;
    while(i < N) {
        while(i+j < N && S[j] == S[i+j]) j++;
        res[i] = j;
        if(j == 0){
            i++;
            continue;
        }
        int k = 1;
        while(i+k < N && k+res[k] < j){
            res[i+k] = res[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return res;
}

int main(){
    int N; cin >> N;
    string S; cin >> S;
    string T;
    int ans = 0;
    rep(i, N-1){
        auto a = Zalgo(S.substr(i));
        rep(j, a.size()){
            int cnt = min(j, a[j]);
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}
