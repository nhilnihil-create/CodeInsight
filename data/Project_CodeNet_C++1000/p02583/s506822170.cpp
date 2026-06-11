#include <iostream>
using namespace std;

int main()
{
    int n = 0 ,l[101];
    int ans = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1 ; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (l[i] == l[j] || l[i] == l[k] || l[j] == l[k])
                {
                    continue;
                }
                else if (l[i] + l[j] > l[k] && l[j] + l[k] > l[i] && l[k] + l[i] > l[j])
                {
                    ans++;
                }
                
            }
            
        }
    }
    cout << ans << endl;
}   