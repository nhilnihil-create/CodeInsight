#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fast_io ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

//sort(arr, arr+n, greater<int>())

//for(int i = 0; i < size; i++)
//    cout << a[i] << " ";

int main()
{
    fast_io;

    map <string, int> m;
    map <string, int>::iterator it;
    int n;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;

        m[temp] += 1;
    }

    int max = 0;
    for(it = m.begin(); it != m.end(); it++)
    {
        max = it->second > max? it->second : max;
    }

    for(it = m.begin(); it != m.end(); it++)
    {
        if(it->second == max) cout << it->first << '\n';
    }
    return 0;
}
