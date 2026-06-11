#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<29;
using namespace std;
using ll = long long;
int main(){
    int N;
    cin >> N;
    vector <string> S(N);
    vector <int> A(N , 0);
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        sort(s.begin() , s.end());
        S[i] = s;
    }
    sort(S.begin() , S.end());
    map <string , int> t;
    ll m = 0;
    for(int i = 0; i < N; i++){
        m += t[S[i]];
        t[S[i]]++;
    }
    cout << m << endl;
}
