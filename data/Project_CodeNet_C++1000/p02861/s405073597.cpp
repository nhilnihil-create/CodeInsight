#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N; cin >> N;
    vector<int> X(N), Y(N);
    for(int i=0; i<N; ++i) cin >> X[i] >> Y[i];

    double d_s = 0;
    for(int i=0; i<N-1; ++i)
    {
        for(int l=i+1; l<N; ++l)
        {
            d_s += sqrt(pow(X[i] - X[l], 2) + pow(Y[i] - Y[l], 2));
        }
    }
    int p = 1;
    for(int i=N-1; i>0; --i) p*=i;
    cout << fixed << setprecision(7) << 2 * p * d_s / (p * N) << endl;
}