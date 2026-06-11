#include <bits/stdc++.h>
using namespace std;
 
int main(void) 
{
    int N,M;

    cin >> N >> M;

    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N);
    iota(C.begin(), C.end(), 0);

    for(int i=0;i<N;++i)
    {
        cin >> A[i] >> B[i];
    }

    sort(
        C.begin(),
        C.end(),
        [&](int x, int y){return A[x] < A[y];}
    );

    int ans = 0;
    int j = 0;
    
    priority_queue<int> que;
    for(int i=1;i<=M;++i)
    {
        while(A[C[j]]==i)
        {
            que.push(B[C[j]]);
            j++;
        }
        if(!que.empty())
        {
            ans += que.top();
            que.pop();
        }
    }

    cout << ans << endl;

    return 0;
}
