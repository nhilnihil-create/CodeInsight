#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n; cin >> n;
    vector<int> sub(n, 0);
    int a;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a;
        sub[a-1]++;
    }
    for (int p:sub) cout << p << endl;
}