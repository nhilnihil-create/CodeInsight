#include<bits/stdc++.h>
#define REP(i, n) for(int i=0; i<n; i++)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    string S[N];
    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }
    sort(S, S+N);
    int cnt = 1;
    int maxcnt = 0;
    for (int i = 0; i < N; i++)
    {
         chmax(maxcnt, cnt);
      	if(i==i-1)break;
        if(S[i]==S[i+1]){
            cnt++;
        }else{
            cnt = 1;
        }

    }
    for (int i = 0; i < N; i++)
    {
        if(maxcnt==cnt)cout << S[i] << endl;
      	if(i==i-1)break;
        if(S[i]==S[i+1]){
            cnt++;
        }else{
            cnt = 1;
        }

    }  
}