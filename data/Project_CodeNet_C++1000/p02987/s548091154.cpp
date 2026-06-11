#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

string s;

int main()
{
    _FastIO;
    cin >> s;
    multiset<int> ms;
    multiset<int>::iterator it;
    for(int i = 0; i < 4; i++){
        ms.insert(int(s[i]));
    }
    string ans = "Yes";
    for(it = ms.begin(); it != ms.end(); it++){
        int k = ms.count(*it);
        if(k != 2)  ans = "No";
    }
    cout << ans << endl;
    return 0;
}
