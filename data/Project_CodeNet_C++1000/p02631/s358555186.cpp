#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<int> v;
    int x = 0;
    cin >> n;
    while (n > 0)
    {
        int a;
        cin >> a;
        x = a ^ x;
        v.push_back(a);
        n--;
    }

    for (int i = 0; i < v.size(); i++)
    {
        v[i] = v[i] ^ x;
        cout << v[i] << " ";
    }

    return 0;
}