#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n;
string s;

int main()
{
    _FastIO;
    cin >> n;
    cin >> s;
    if(n >= 3200 && s != "red"){
        cout << s << endl;
    }
    else
        cout << "red" << endl;
    return 0;
}
