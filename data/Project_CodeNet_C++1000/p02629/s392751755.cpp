#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
using namespace std;

long long N;
string ans;

int main()
{
    string c;
    cin >> N;

    while(N>0)
    {
       c=(N-1)%26+'a';
       ans.insert(0,c);
       N=(N-1)/26;
    }

    cout << ans << endl;
    return 0;
}