#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,x;
    set <int> s;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        s.insert(x);
    }
    if(s.size() == n)
        cout << "YES";
    else
        cout << "NO";
}
