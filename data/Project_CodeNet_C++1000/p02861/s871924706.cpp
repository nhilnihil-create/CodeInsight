#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const double pi = acos(-1);
double dist(double x, double y){
    return (x - y) * (x - y);
}
int main()
{
    Hello
    int n;
    cin >> n;
    int arr[n], cntr = 0;
    double av = 0;
    pair<double, double> pr[n];
    for(int i = 0; i < n; i++) arr[i] = i;
    for(int i = 0; i < n; i++) cin >> pr[i].first >> pr[i].second;
    do{
        cntr++;
        for(int i = 0; i < n - 1; i++)
            av += (sqrt(dist(pr[arr[i]].first, pr[arr[i + 1]].first) +
                       (dist(pr[arr[i]].second, pr[arr[i + 1]].second))));
    }while (next_permutation(arr, arr + n));
    cout << fixed << setprecision(6) << av/cntr;
    return 0;
}