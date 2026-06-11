#include <bits/stdc++.h>

using namespace std;



int main(int argc, char *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    int cnt = 0;
    
    for (int i = 1; i <= N; i += 1) {
        string s = to_string(i);
        if (s.length() % 2 != 0) {
            cnt++;
        }
    }
    
    cout << cnt << endl;
    
    return 0;
}
