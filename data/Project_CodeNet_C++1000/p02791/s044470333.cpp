#include <iostream>
#include <algorithm>
#include <vector>
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

    int n;
    cin >> n;

    vector <int> v;

    while(n--)
    {
        int temp;
        cin >> temp;

        v.emplace_back(temp);
    }

    int res = 1;

    for(int i = 0; i < v.size() - 1; i++)
    {
        if(v[i] > v[i + 1]) res++;
        else v[i + 1] = v[i];
    }

    cout << res << '\n';
    return 0;
}
