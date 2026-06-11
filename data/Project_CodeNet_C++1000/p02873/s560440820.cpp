#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    string S;
    cin >> S;

    vector<int> A(S.size()+1,-1);
    vector<int> idx;

    if (S[0]=='<') {
        A[0]=0;
        idx.push_back(0);
    }
    if (S[S.size()-1]=='>') {
        A[S.size()]=0;
        idx.push_back(S.size());
    }

    for (int i=1; i<S.size(); i++) {
        if (S[i-1]=='>' && S[i]=='<') {
            A[i]=0;
            idx.push_back(i);
        }
    }

    rep(i,idx.size()) {
        int tmp = idx[i];
        while (idx[i]>0 && S[tmp-1]=='>') {
            A[tmp-1] =  max(A[tmp-1],A[tmp] + 1);
            tmp--;
        }
        tmp = idx[i];
        while (idx[i]<S.size() && S[tmp]=='<') {
            A[tmp+1] = max(A[tmp+1],A[tmp] + 1);
            tmp++;
        }
    }
    ll ans = 0;
    rep(i,S.size()+1) {
        ans += A[i];
    }
    cout << ans  << endl;
}
