#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    
    int idx = -1;
    for(int i=1; i<N; i++)
    {
        if(idx==-1 && A[i-1] > A[i]) idx = i-1;
        else if(A[i-1] > A[i])
        {
            swap(A[idx], A[i]);
            break;
        }
    }
    string ans = "YES";
    for(int i=1; i<N; i++)
    {
        if(A[i-1] > A[i]) ans = "NO";
    }
    cout << ans << endl;

    return 0;
}
