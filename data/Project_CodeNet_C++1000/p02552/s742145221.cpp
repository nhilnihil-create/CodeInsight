#include <bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld long double
#define f first
#define s second
#define matrix vector<vector<char>>
#define zero(n,m) matrix(n , vector<char>(m,'0'))
#define one(n,m) matrix(n , vector<ll>(m,1))
#define pii pair<int,int>
#define point complex<ld>
#define angle(a) (atan2((a).imag() , (a).real() ))
#define pi acos(-1)
#define X real()
#define Y imag()

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int x;
    cin >> x;
    cout << !x << '\n';

    return 0;
}