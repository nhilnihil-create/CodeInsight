// In The Name Of God

#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long

using namespace std;

string a;

int main()
{
    IOS;
    cin >> a;
    if(a[a.size() - 1] == 's')
        a += "es";
    else
        a += 's';
    cout << a << endl;
}
