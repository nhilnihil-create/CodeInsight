#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_in_out  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    fast_in_out;
    int n;
    cin >> n;
    set <int> v;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.insert(x);
    }
    if(v.size() < n)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
}
