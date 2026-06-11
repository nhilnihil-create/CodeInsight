#include <iostream>
#include <map>
#include <vector>
#include <iomanip>

#include <cfenv>
#include <cmath>
typedef long long int ll;

using namespace std;

int main()
{

    ll N;

    cin >> N;

    vector<ll> A(N);

    map<int, int> mp;


    ll sum=0;

    for (ll i = 1; i <= N; i++)
    {

        ll a;
        cin >> a;

        sum +=mp[i-a];

        mp[i+a]++;

    
    }

    

    cout << sum << endl;

    return 0;
}
