#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int min_z, max_z;
    int min_w, max_w;
    for (int i = 0; i < N; ++i)
    { 
        int x, y;
        cin >> x >> y;

        int z = x + y;
        int w = x - y;

        if (i == 0)
        {
            min_z = max_z = z;
            min_w = max_w = w;
        }
        else
        {
            min_z = min(z, min_z);
            min_w = min(w, min_w);
            max_z = max(z, max_z);
            max_w = max(w, max_w);
        }
    }

    cout << max((max_z - min_z), (max_w - min_w)) << endl;

    return 0;
}
