#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;


int main()
{
    int P, Q, R;
    cin >> P >> Q >> R;
    vector<int> v(3);
    v[0]= P;v[1]=Q;v[2] = R;
    sort(v.begin(),v.end());
    cout << v[0]+v[1];
}
