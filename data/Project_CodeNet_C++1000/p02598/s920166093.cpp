#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int N;
    long int K;
    cin >> N;
    cin >> K;
    vector<long double> A(N);
    long int i;
    for (i = (long int)0; i < N; i++)
    {
        cin >> A[i];
    }
    long int d = (long int)0;
    long int l = (long int)*max_element(A.begin(), A.end());
    long int count;
    long double ans;
    long int dist;
    while (d + (long int)1 < l)
    {
        count = (long int)0;
        dist = (d + l) / (long int)2;
        for (i = (long int)0; i < N; i++)
        {
            ans = A[i] / (long double)dist;
            if (ans == (long double)(long int)ans)
            {
                count += (long int)ans - (long int)1;
            }
            else
            {
                count += (long int)ans;
            }
        }
        if (count <= K)
        {
            l = dist;
        }
        else
        {
            d = dist;
        }
    }
    cout << l << endl;
    return 0;
}