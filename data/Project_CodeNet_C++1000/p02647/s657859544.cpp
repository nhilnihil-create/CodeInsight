#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,a,b) for (int i=a; i<b; ++i)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    vector <int> A(N);
    vector <int> additions(N+1, 0);
    for (int i=0; i<N; ++i)
    {
        cin >> A[i];
    }
    while (K--)
    {
        queue < pair < pair <int, int>, long long > > Q;
        for (int i=0; i<N; ++i)
        {
            long long val = A[i];
            if (val) 
            {
                additions[max(i-val,0ll)] += 1;
                additions[i]-=1;
                additions[i+1] += 1;
                additions[min((ll)N, i+val+1)] -=1;
            }
            additions[i]+=(1-val);
            additions[i+1]-=(1-val);
        }
        bool finished = true;
        A[0]=A[0]+additions[0];
        for (int i=1; i<N; ++i)
        {
            additions[i]+=additions[i-1];
            A[i] = A[i]+additions[i];
        }
        additions.assign(N+1, 0);

        for (int i=0; i<N; ++i)
        {
            if (A[i]!=N) {finished=false; break;}
        }
        if (finished) break;
    }
    for (int i=0; i<N; ++i) cout << A[i] << " "; cout << "\n";
    return 0;
}