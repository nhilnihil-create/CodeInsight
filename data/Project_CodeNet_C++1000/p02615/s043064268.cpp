#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<long> A(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    long ans=A[0];
    int c=N-2;
    int k=1;
    while (c>0)
    {
        if (c>=2)
        {
           ans+=A[k]*2;
           c-=2; 
        }else
        {
            ans+=A[k];
            c--;
        }
        k++;
    }
    cout << ans << endl;
}