#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

struct Music
{
    string title;
    int length;
};

int main()
{
    int n;
    cin >> n;
    vector<Music> vs(n);

    for (auto& v : vs)
    {
        cin >> v.title >> v.length;
    }
    string x;
    cin >> x;

    int count = 0;
    bool is_sleep = false;
    for (auto& v : vs)
    {
        if (v.title == x)
        {
            is_sleep = true;
        }
        else if (is_sleep)
        {
            count += v.length;
        }
    }
    cout << count << endl;
}
