#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N;
    cin >> N;
    vector<int> x(N), y(N);

    vector<int> indices(N);
    for (int i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i];
        indices[i] = i;
    }
    double sum = 0;
    int totalCases = 0;
    do{
        for (int i = 1; i < N; i++)
        {
            int from = indices[i-1];
            int to = indices[i];
            int sqrDist = (x[to] - x[from])*(x[to] - x[from]) + (y[to]- y[from])*(y[to] - y[from]);
            sum += sqrt(sqrDist);
        }
        totalCases++;
    } while(next_permutation(indices.begin(), indices.end()));
    double ans = sum / totalCases;
    cout << fixed << setprecision(8) << ans << endl;
    return 0;
}
