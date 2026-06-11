#include <iostream>
#include <set>
#define ll long long

using namespace std;

ll n2, n;
multiset <int> s1, s2;

int main()
{
    cin >> n;
    n2 = (1 << n);

    for(int i = 1; i <= n2; ++i)
    {
        int x;
        cin >> x;
        s1.insert(x);
    }

    auto it1 = s1.end();
    --it1;
    s2.insert(*it1);
    s1.erase(it1);

    for(int i = 1; i <= n; ++i)
    {
        for(auto it2 = s2.begin(); it2 != s2.end(); ++it2)
        {
            auto it3 = s1.lower_bound(*it2);

            if(it3 == s1.begin())
            {
                cout << "No"; ///pe
                return 0;
            }

            --it3;

            if(*it3 > *it2)
            {
                cout << "No"; ///pe
                return 0;
            }

            s2.insert(*it3);
            s1.erase(it3);
        }
    }

    cout << "Yes"; ///p
    return 0;
}
