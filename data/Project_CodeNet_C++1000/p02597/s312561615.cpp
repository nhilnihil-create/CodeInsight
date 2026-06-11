#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string c;
    cin >> c;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i] == 'R')
        {
            count++;
        }
    }
    int red_count = 0;
    for (int i = 0; i < count; i++)
    {
        if (c[i] == 'R')
            red_count++;
    }
    cout << count - red_count << endl;
}