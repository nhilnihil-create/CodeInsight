#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
const int maxn = 1e5 + 5;

int main()
{
    ios::sync_with_stdio(false);
    int a , b; cin >> a >> b;
    cout << b + 100 * (10 - min(10 ,a)) << endl;
    return 0;
}
