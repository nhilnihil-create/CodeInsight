#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;


int main(void)
{
    int N;
    cin >> N;
    vector<double> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    double res = 0;
    for (int i = 0; i < N; i++)
    {
        res+= 1/(double)A[i];
    }
    res= 1/res;
    cout << res;
    
    }
