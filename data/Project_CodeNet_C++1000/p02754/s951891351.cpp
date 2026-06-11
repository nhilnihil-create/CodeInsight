#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using namespace std;
typedef vector<int> vi;

int main(){
    long long N, A, B, ans = 0, tmp;
    cin >> N >> A >> B;

    tmp = A + B;
    ans += A * (N / tmp);

    ans += min(A, N % (A + B));
    
    cout << ans << endl;

    return 0;
}