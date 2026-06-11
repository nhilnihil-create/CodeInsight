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

    vector<int> B(N);
    for(int i=N; i>0; i--)
    {
        int num = 0;
        for(int j=i*2; j<=N; j+=i)
        {
            if(B[j-1]==1) num++;
        }
        if(num%2==0 && A[i-1]==1) B[i-1] = 1;
        else if(num%2==1 && A[i-1]==0) B[i-1] = 1;
        else B[i-1] = 0;
    }

    int M = 0;
    for(auto b : B) if(b==1) M++;

    cout << M << endl;
    for(int i=0; i<N; i++)
    {
        static bool first = true;
        if(B[i]==1)
        {
            if(!first) cout << ' ';
            first = false;
            cout << i+1;
        }
    }
    if(M!=0) cout << '\n';

    return 0;
}
