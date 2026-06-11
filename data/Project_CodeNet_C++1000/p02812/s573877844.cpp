#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define pi acos(-1.0)

int main()
{
    ll i, j, a, b, k, n, m, cnt = 0;
    string s;
    cin >> n >> s;
    for(i = 0; i < n - 2; i++){
        if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')
            cnt++;
    }
    
    cout << cnt << endl;
    
    return 0;
}
