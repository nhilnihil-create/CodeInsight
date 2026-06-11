#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int ctoi(char c){
    switch (c){
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default: return 0;
    }
}

int main(){
    int N;
    cin >> N;
    vector<vector<string> > vec(10, vector<string>(0));
    vec[0].push_back("0");
    rep(i,9){
        for (int j = 0; j < vec[i].size(); j++){
            int x = 0;
            rep(k,i + 1){
                x = max(x, ctoi(vec[i][j][k]));
            }
            for (int k = 0; k <= x + 1; k++){
                vec[i + 1].push_back(vec[i][j] + to_string(k));
            }
        }
    }
    rep(i, vec[N - 1].size()){
        rep(j, N){
            if (ctoi(vec[N - 1][i][j]) == 0) cout << 'a';
            if (ctoi(vec[N - 1][i][j]) == 1) cout << 'b';
            if (ctoi(vec[N - 1][i][j]) == 2) cout << 'c';
            if (ctoi(vec[N - 1][i][j]) == 3) cout << 'd';
            if (ctoi(vec[N - 1][i][j]) == 4) cout << 'e';
            if (ctoi(vec[N - 1][i][j]) == 5) cout << 'f';
            if (ctoi(vec[N - 1][i][j]) == 6) cout << 'g';
            if (ctoi(vec[N - 1][i][j]) == 7) cout << 'h';
            if (ctoi(vec[N - 1][i][j]) == 8) cout << 'i';
            if (ctoi(vec[N - 1][i][j]) == 9) cout << 'j';
        }
        cout << endl;
    }
}