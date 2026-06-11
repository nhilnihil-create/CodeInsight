#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N;
    cin >> N;
    vector<int> P(N), Q(N);

    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
    }
    
    for (int i = 0; i < N; i++)
    {
        cin >> Q[i];
    }
    

    vector<int> from, to;
    if(P < Q){
        from = P;
        to = Q;
    } else {
        from = Q;
        to = P;
    }

    int ans = 0;
    while(true){

        if(from == to) {
            break;
        }
        next_permutation(from.begin(), from.end());
        ans++;
    }
    cout << ans << endl;
    return 0;
}
