#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int main()
{
    int n, k;
    vector<int> h;
    cin >> n >> k;

    h.resize(n);
    for (int i=0; i<n; i++)
    {
        cin >> h[i];
    }

    int count = 0;
    for (int i=0; i<n; i++)
    {
        if(h[i] >= k)
        {
            count++;
        }
        
    }

    cout << count << endl;

    return 0;
}