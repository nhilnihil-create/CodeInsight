#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    int n, answer = 0;
    cin >> n;
    vector<int> p(n);
    for (int count = 0; count < n; count++)
    {
        cin >> p.at(count);
    }
    for (int count = 1; count < n - 1; count++)
    {
        if (p.at(count - 1) < p.at(count) && p.at(count) < p.at(count + 1) ||
            (p.at(count - 1) > p.at(count) && p.at(count) > p.at(count + 1)))
        {
            answer++;
        }
    }
    cout << answer << endl;
}