#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

    set<int> d;

    int i,k;

    for(i=0;i<n;i++)
    {
        cin >> k;

        d.insert(k);


    }

    if(d.size()==n)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
