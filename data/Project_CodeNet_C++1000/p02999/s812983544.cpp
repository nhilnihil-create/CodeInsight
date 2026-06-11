#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int x , a;

int main()
{
    _FastIO;
    cin >> x >> a;
    if(x >= a)  cout << "1";
    cout << "0" << endl;
    return 0;
}
