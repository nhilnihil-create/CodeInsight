#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ll a;

    cin>> a;

    ll b = a;

        ll c3 = a %10;
        a /= 10;

        ll c2 = a % 10;
        a/=10;

        ll c1 = a %10;

    if(c1 == 7 || c2 == 7 || c3 == 7) cout<< "Yes\n";

    else cout<< "No\n";

	return 0;
}

