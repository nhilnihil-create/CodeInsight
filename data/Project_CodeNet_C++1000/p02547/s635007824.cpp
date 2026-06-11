#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define mod 1e9+7
#define INF 1 << 30
#define MAX (1 << 20)
#define NINF (-(1 << 30))
#define Point pair<int, int>
#define triplet pair<pair<int, int>, int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<Point> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i].first >> vec[i].second;


    for (int i = 2; i < n; i++){
        if(vec[i].first == vec[i].second && vec[i-1].first == vec[i-1].second && vec[i-2].first == vec[i-2].second) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}