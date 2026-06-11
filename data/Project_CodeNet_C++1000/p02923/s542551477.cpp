#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{

    int N;
    cin >> N;
    int res = 0, m = 0;
    int preH;
    cin >> preH;
    for (int i = 1; i < N; i++)
    {
        int H;
        cin >> H;
        if (H <= preH)
        {
            m++;
            res = max(res, m);
        }
        else
        {
            res = max(res, m);
            m = 0;
        }
        preH = H;
    }
    cout << res << endl;
    return 0;
}
