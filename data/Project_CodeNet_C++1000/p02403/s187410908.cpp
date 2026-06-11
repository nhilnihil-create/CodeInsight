#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main(int argc, char *argv[])
{
    int a, b;
    vector<tuple<int, int>> tv;

    while (1)
    {
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        tv.push_back(tuple<int, int>(a, b));
    }

    for (tuple<int, int> t : tv)
    {
        for (int i = 0; i < get<0>(t); i++)
        {
            for (int j = 0; j < get<1>(t); j++)
            {
                cout << "#";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}