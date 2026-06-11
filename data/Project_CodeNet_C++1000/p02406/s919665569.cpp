#include <iostream>
#include <string>
using namespace std;

void call(int n);
bool contains(const string &str1, const string &str2);

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    call(n);

    return 0;
}

void call(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        if ((i % 3 == 0) || contains(to_string(i), "3"))
        {
            cout << " " << i;
            continue;
        }
    }
    cout << endl;
}

bool contains(const string &str1, const string &str2)
{
    string::size_type pos = str1.find(str2);
    if (pos == string::npos)
    {
        return false;
    }
    return true;
}