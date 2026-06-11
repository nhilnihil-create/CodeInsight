#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> dict;
    string s, max_s, max_e_s;
    int max_length = 0, max_emerge = 0;
    while (cin >> s)
    {
        dict[s]++;
        if (s.size() > max_length)
        {
            max_length = s.size();
            max_s = s;
        }
    }
    for (auto t = dict.begin(); t != dict.end(); t++)
    {
        if (t->second > max_emerge)
        {
            max_emerge = t->second;
            max_e_s = t->first;
        }
    }
    cout << max_e_s << " " << max_s << endl;
    return 0;
}

