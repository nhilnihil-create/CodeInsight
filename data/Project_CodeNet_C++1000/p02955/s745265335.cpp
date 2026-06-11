#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

#define rep(i, x, n) for (int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
vector<long long> yaku(long long n)
{
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ret.push_back(i);
            if (i * i != n)
            {
                ret.push_back(n / i);
            }
        }
    }
    return ret;
}
int main()
{
    long long N, K;
    cin >> N >> K;
    vector<long long> A(N);
    long long sum = 0;
    rep(i, 0, N)
    {
        cin >> A[i];
        sum += A[i];
    }
    vector<long long> v = yaku(sum);
    sort(v.begin(), v.end(), greater<long long>());
    // for (auto m : v)
    // {
    //     cout << m << endl;
    // }
    for (auto m : v)
    {
        vector<long long> modA(N);
        rep(i, 0, N)
        {
            modA[i] = A[i] % m;
        }
        sort(modA.begin(), modA.end());
        int l = 0;
        int r = N - 1;
        long long tmp = 0;
        bool kekka = false;
        long long count = 0;
        while (true)
        {
            //cout << m << "," << l << "," << r << endl;
            if (l == r)
            {
                if (tmp <= 0)
                {

                    count += modA[l];
                }
                if ((modA[l] + tmp) % m == 0 && count <= K)
                {
                    kekka = true;
                }
                break;
            }
            else if (modA[l] == 0)
            {
                l++;
                continue;
            }
            else if (tmp <= 0)
            {
                tmp += modA[l];
                count += modA[l];
                l++;
            }
            else
            {
                tmp -= m - modA[r];
                r--;
            }
        }
        if (kekka)
        {
            cout << m << endl;
            break;
        }
    }
}