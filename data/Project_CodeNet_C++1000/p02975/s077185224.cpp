#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    int n;
    cin >> n;
    set<int> st;
    multiset<int> mst;
    for(int i = 0;i < n;i++)
    {
        int a;
        cin >> a;
        st.insert(a);
        mst.insert(a);
    }
    auto itr = mst.end();
    itr--;
    if(st.size() == 1 && *mst.begin() == 0)
    {
        cout << "Yes\n";
    }
    else if(n % 3 == 0 && st.size() == 2 && mst.count(0) == n / 3)
    {
        cout << "Yes\n";
    }
    else if(n % 3 == 0 && st.size() == 3 && mst.count(*mst.begin()) == n / 3 && mst.count(*itr) == n / 3)
    {
        auto st_itr = st.begin();
        int x = *st_itr;
        st_itr++;
        int y = *st_itr;
        st_itr++;
        int z = *st_itr;
        if(!(x ^ y ^ z))
        {
        cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}