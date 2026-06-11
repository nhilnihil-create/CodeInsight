#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s.erase(unique(s.begin(),s.end()),s.end());
    cout << s.size() << endl;
    return 0;
}