#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    string s;
    cin >> s;
    int count=0;
    for (int i = 0; i < N; i++){
        if (s.at(i)=='W')
        {
            count++;
        }
    }
    int ans=0;
    for (int i = 0; i < N-count; i++){
        if (s.at(i)=='W')
        {
            ans++;
        }
        
    }
    cout << ans << endl;
}