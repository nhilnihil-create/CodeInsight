#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat>

using namespace std;

int main(int argc, char const *argv[])
{
    long long N;
    cin >> N;
    vector<long long> L;
    long long pre = 0;
    long long in;
    for (int i = 0; i < N; i++)
    {
        cin >> in;
        L.emplace_back(in + pre);
        pre = L[i];
    }

    double min = DBL_MAX;
    double d;
    for (int i = 0; i < N; i++)
    {
        d = abs((double)L[i] -  (double)L[N - 1] / 2.0);
        if (d < min) min = d;
    }
    
    cout << (long long)(min / 0.5) << endl;
    
    return 0;
}