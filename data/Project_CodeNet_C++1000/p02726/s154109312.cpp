#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N,X,Y;
    cin >> N >> X >> Y;
    vector<vector<int> > vec(N + 1,vector<int>(N + 1));
    for (int i = 1; i <= N - 1; i++){
        for (int j = i + 1; j <= N; j++){
            vec[i][j] = min(j - i, min(max(X - i, i - X) + 1 + max(Y - j, j - Y), max(Y - i, i - Y) + 1 + max(X - j, j - X)));
        }
    }
    vector<int> answer_vec(N,0);
    for (int i = 1; i <= N - 1; i++){
        for (int j = i + 1; j <= N; j++){
            answer_vec[vec[i][j]]++;
        }
    }
    for (int i = 1; i <= N - 1; i++){
        cout << answer_vec[i] << endl;
    }
}

