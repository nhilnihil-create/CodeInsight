#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define vi vector<int>
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {

    
    int N; cin >> N;
    int A[N]; rep(i,N) cin >> A[i];

    int r[N] = {-1};
    int l[N] = {-1};

    int current_left_max = A[0];
    for(int i = 0; i < N; i++){
        current_left_max = max(current_left_max, A[i]);
        l[i] = max(current_left_max, l[i]);
    }

    int current_right_max = A[N-1];
    for(int i = N-1; i>=0; i--){
        current_right_max = max(current_right_max, A[i]);
        r[i] = max(current_right_max, r[i]);
    }


    for(int i = 0; i < N; i++){
        if(i == 0) cout << r[i+1] << endl;
        else if(i == (N-1)) cout << l[i-1] << endl;
        else cout << max(l[i-1], r[i+1]) << endl;
    }


    return 0;
}