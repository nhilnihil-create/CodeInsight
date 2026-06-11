#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
vector<string> S;

int main() { 
    cin >>N;
    S.resize(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    set<string> st;
    for(int i=0; i <N; i++){
      st.insert(S[i]);
    }
    ll cnt = 0;
    for (auto i: st){
      cnt++;
    }
    cout<< cnt<< endl;
    return 0;
}