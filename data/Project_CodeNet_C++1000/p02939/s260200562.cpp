#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef pair<int,int> pii;
const int MN = 2e5+5;
int N,D[MN][2];
string S;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> S;
    int N = S.size();
    D[0][1] = 1;
    D[0][2] = -1e9;
    D[1][1] = -1e9;
    if(S[0]!=S[1]) D[1][1] = 2;
    D[1][2] = 1;
    for(int i=2; i<N; i++){
        D[i][1] = D[i-1][2]+1;
        if(S[i-1]!=S[i]) D[i][1] = max(D[i][1],D[i-1][1]+1);
        D[i][2] = D[i-2][1]+1;
        if(i>=3&&(S[i-2]!=S[i]||S[i-3]!=S[i-1])) D[i][2] = max(D[i][2],D[i-2][2]+1);
    }
    cout << max(D[N-1][1],D[N-1][2]);
}
