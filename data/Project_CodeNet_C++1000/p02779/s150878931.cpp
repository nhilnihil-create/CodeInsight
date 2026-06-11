#include <bits/stdc++.h>
using namespace std;
typedef long double ll;

ll N;
vector<ll> A;

int main() { 
    cin >>N;
    A.resize(N);
    for (int i = 0; i<N; i++) cin >> A[i];
    set<ll> st;
    for (int i = 0; i < N; i++) st.insert(A[i]);
    if(A.size()==st.size())cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}