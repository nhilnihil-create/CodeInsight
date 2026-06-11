#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const double pi = acos(-1);
int main()
{
    Hello
    int n;
    string s;
    cin >> n >> s;
    if(n % 2)
        return cout << "No", 0;
    string t = s.substr(0, n/2);
    if(t + t == s) cout << "Yes";
    else cout << "No";
    return 0;
}