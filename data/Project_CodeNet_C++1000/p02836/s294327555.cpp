#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define pi acos(-1.0)

int main()
{
    ll i, j, n, m, cnt = 0;
    string s;
    cin >> s;
    for(i = 0, j = s.size() - 1; i < j; )
    {
        if(s[i] != s[j]){
            cnt++;
        }
        i++;
        j--;
    }
    cout << cnt << endl;

    return 0;
}
