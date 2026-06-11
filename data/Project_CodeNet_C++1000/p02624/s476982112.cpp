#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<cmath>
#include<iomanip>

using namespace std;


int main()
{
    long long N; cin >> N;

    vector<long long> fac(N+1);

    for(int i=1; i<=N; ++i)
    {
        for(int k=1; k*i<=N; ++k)
        {
            ++fac[k*i];
        }
    }

    long long ans = 0;
    for(int i=1; i<=N; ++i)
    {
        ans += fac[i] * i;
    }

    cout << ans << endl;
}
