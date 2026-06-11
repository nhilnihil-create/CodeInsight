#include <iostream>

using namespace std;

bool solve(double dist, double t, double s)
{
    if (dist / s <= t)
        return true;
    return false;
}
int main()
{
    double dist, t, s;
    cin >> dist >> t >> s;
    bool res = solve(dist, t, s);
    if (res)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}