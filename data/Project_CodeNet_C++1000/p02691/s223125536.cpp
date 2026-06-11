#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long N;
    cin >> N;
    vector<long long> A(N);
    for (long long i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    vector<long long> x(N);
    vector<long long> y(N);
    for (long long i = 0; i < N; i++)
    {
        x[i] = i+A[i];
        y[i] = i-A[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    long long countx = 0;
    long long county = 0;
    long long count = 0;
    while(1)
    {
        if (countx == N || county == N)
        {
            break;
        }
        if (x[countx] < y[county])
        {
            countx++;
        }
        else if (x[countx] > y[county])
        {
            county++;
        }
        else
        {
            long long prex = 0;
            long long prey = 0;
            while(1)
            {
                if (x[countx+prex] != x[countx])
                {
                    break;
                }
                prex++;
            }
            while(1)
            {
                if (y[county+prey] != y[county])
                {
                    break;
                }
                prey++;
            }
            count += prex * prey;
            countx += prex;
            county += prey;
        }
    }
    cout << count << endl;
}