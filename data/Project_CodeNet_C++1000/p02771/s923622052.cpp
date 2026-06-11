#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<int> s;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    if (s.size()==2) cout << "Yes\n";
    else cout << "No\n";
}