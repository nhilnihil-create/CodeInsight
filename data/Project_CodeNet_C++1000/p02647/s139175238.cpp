#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <cstdio>
#include <numeric>
#include <iomanip>

using namespace std;

using ll = long long;

ll N, K;
vector<ll> A;
vector<ll> B;

int main()
{
    cin >> N >> K;
    A.resize(N);
    B.resize(N+1);
    for(int i = 0;i < N;i++)
    {
        cin >> A[i];
    }
    ll logN = log2(N)+100;
    for(ll i = 0;i < min(K, logN) ;i++)
    {
        fill(B.begin(), B.end(), 0LL);
        for(ll j = 0; j < N;j++)
        {
            B[max(j-A[j], 0LL)]++;
            if(j+A[j] < N-1)B[j+A[j]+1]--;
        }
        for(ll j = 0;j < N;j++)
        {
            A[j] = B[j];
            B[j+1] += B[j];
        }
    }
    for(ll i = 0;i < N;i++)
    {
        cout << B[i];
        if(i == N-1)
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }
    return 0;
}