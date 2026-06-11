#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N,K,C;
    cin >> N >> K >> C;
    string S;
    cin >> S;
    vector<int> saki_bataraki(K);
    vector<int> ato_bataraki(K);
    int count = C;
    int next = 0;
    rep(i,N){
        if (next == K){
            break;
        }
        else if (count < C || S[i] == 'x'){
            count++;
        }
        else{
            saki_bataraki[next] = i;
            count = 0;
            next++;
        }
    }
    count = C;
    next = K - 1;
    for (int i = N - 1; i >= 0; i--){
        if (next == -1){
            break;
        }
        else if (count < C || S[i] == 'x'){
            count++;
        }
        else{
            ato_bataraki[next] = i;
            count = 0;
            next--;
        }
    }
    vector<int> ans(0);
    rep(i,K){
        if (saki_bataraki[i] == ato_bataraki[i]){
            ans.push_back(saki_bataraki[i] + 1);
        }
    }
    rep(i, ans.size()) cout << ans[i] << endl;
}