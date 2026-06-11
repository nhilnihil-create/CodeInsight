#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int n;
    cin >> n;
    multiset<int> ms;
    for(int i = 0; i < pow(2,n); i++)
    {
        int a;
        cin >> a;
        ms.insert(a);
    }
    int ma = *ms.rbegin();
    if(ms.count(ma) != 1)
    {
        cout << "No" << endl;
        return 0;
    }
    multiset<int> make;
    make.insert(ma);
    ms.erase(ms.find(ma));
    for(int i = 0; i < n; i++)
    {
        int size = make.size();
        auto itr = make.begin();
        multiset<int> tmp;
        for(int j = 0; j < size; j++)
        {
            auto msitr = ms.lower_bound(*itr);
            if(msitr == ms.begin())
            {
                cout << "No" << endl;
                return 0;
            }
            msitr--;
            tmp.insert(*msitr);
            ms.erase(msitr);
            itr++;
        }
        make.insert(tmp.begin(), tmp.end());
    }
    cout << "Yes" << endl;
}
