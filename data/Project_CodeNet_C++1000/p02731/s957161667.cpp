#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    ld n;
    cin >> n;
    ld s1 = n / 3;
    ld sum = s1 * s1 * s1;
    cout << fixed << setprecision(12) << sum << endl;

    return 0;
}
