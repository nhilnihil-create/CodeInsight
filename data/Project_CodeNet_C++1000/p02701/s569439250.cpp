#include <bits/stdc++.h>
using namespace std;

void Main()
{
    int n;
    cin >> n;
    map<string, int> got;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        got[s]++;
    }
   
    cout << got.size() << endl;
}

int main(int argc, char **argv)
{
    Main();
    return 0;
}
