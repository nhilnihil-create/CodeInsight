// https://atcoder.jp/contests/abc145/tasks/abc145_c
#include <bits/stdc++.h>
using namespace std;
// example of listing permuations
void list_permutation()
{
    int n;
    cin >> n;
    vector<int> one_case;
    for (int i = 0; i < n; i++)
        one_case.push_back(i);

    do
    {
        for (auto num : one_case)
        {
            cout << num << " ";
        }
        cout << endl;

    } while (next_permutation(one_case.begin(), one_case.end()));
}
using pii = pair<double, double>;
int main()
{
    int n;
    int pattern = 1;
    cin >> n;
    vector<int> one_case;
    vector<pii> pairs;
    for (int i = 1; i <= n; i++)
    {
        pattern *= i;
        double x, y;
        cin >> x >> y;
        pairs.push_back(pii(x, y));
        one_case.push_back(i - 1);
    }
    long double sum = 0;
    do
    {
        for (int i = 0; i < one_case.size() - 1; i++)
        {
            sum += sqrt(pow(pairs[one_case[i]].first - pairs[one_case[i + 1]].first, 2.0) + pow(pairs[one_case[i]].second - pairs[one_case[i + 1]].second, 2.0));
        }

    } while (next_permutation(one_case.begin(), one_case.end()));
    cout << fixed << setprecision(10) << (sum / pattern);
}