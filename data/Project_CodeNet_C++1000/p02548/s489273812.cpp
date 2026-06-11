#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int res = 0;
    for(int i=1;i<N;i++){
        res += (N-1)/i;
    }
    cout << res << endl;

    return 0;
}