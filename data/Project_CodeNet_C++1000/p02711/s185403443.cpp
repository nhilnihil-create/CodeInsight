#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string  N;
    cin >> N;

    if (N.find('7') == string::npos)
        cout << "No\n";
    else
        cout << "Yes\n";
    return 0;
}