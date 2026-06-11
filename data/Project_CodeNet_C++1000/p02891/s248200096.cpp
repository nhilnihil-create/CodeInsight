#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;
const int INF = 1e8;

int main(){
    string S; Int K;
    cin >> S >> K;

    Int N = S.size();
    Int ans = 0;
    
    Int head = -1, tail = N;
    if(S[0] == S[N-1]){
        while(S[0] == S[head+1]) head++;

        while(S[0] == S[tail-1]) tail--;

        Int n_head = head+1, n_tail = N-tail;

        ans += n_head/2 + n_tail/2;
        ans += (n_head+n_tail)/2 * (K-1);
    }

    if(head == N-1){
        if(N % 2 == 0) cout << N/2 * K << endl;
        else {
            if(K % 2 == 0) cout << N * K/2 << endl;
            else cout << N * (K/2) + N/2 << endl;
        }
        return 0;
    }
    

    for(int i=head+1; i<tail-1; i++){
        if(S[i+1] == S[i]){
            S[i+1] = '0';
            ans += K;
        }
    }
    cout << ans << endl;
}
