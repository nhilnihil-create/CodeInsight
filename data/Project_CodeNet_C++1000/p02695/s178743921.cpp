#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N,M,Q; cin >> N >> M >> Q;
    vector<int> a(Q),b(Q),c(Q),d(Q);
    for(int i=0; i < Q; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--,b[i]--;
    }

    vector<int> A(N);
    string nm = "";
    for (int i=0; i<M ; i++){
        nm += "0";
    }
    for (int i=0; i<N ; i++){
        nm += "1";
    }

    int ans = 0;
    do {
        int count=0;
        int j=0;
        if(nm[0] == '1') continue;
        for(int i = 0; i< N+M; i++){
            if(nm[i] == '0') count++;
            if(nm[i] == '1'){
                A[j] = count;
                j++;
            }
        }

        int score = 0;
        for(int q = 0; q < Q; q++){
            if(A[b[q]] - A[a[q]] == c[q]){
                score += d[q];
            }
        }
        ans = max(score, ans);

    } while (std::next_permutation(nm.begin(), nm.end()));

    cout << ans << endl;
}