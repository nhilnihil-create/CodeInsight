#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    sort(all(vec));
    bool ans = true;
    rep(i,N - 1){
        if (vec[i] == vec[i + 1]) ans = false;
    }
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}

