#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int N; cin >> N;

    int rcnt = 0;
    vector<char> C(N), D(N);
    for(int i=0; i<N; ++i)
    {
        cin >> C[i];
        D[i] = C[i];
        if(C[i] == 'R') ++rcnt;
    }

    int ans = 0;
    
    sort(D.begin(), D.end());
    for(int i=0; i<N; ++i)
    {
        if(D[i] == 'W')
        {
            break;
        }
        if(D[i] != C[i]) ++ans;
    }

    ans = min(ans, min(rcnt, N - rcnt));
    
    cout << ans << endl;
}