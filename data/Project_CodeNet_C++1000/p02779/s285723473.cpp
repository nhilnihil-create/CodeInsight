#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
//#include <fstream>

#define ll long long int
using namespace std;

void Solve()
{
    //cout << "Case " << t << ": ";
    set<int>p;
    int n, x;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> x;
        p.insert(x);
    }
    if(p.size() == n) cout << "YES";
    else cout << "NO";
}

int main()
{
    //ios_base::sync_with_stdio( false );
    //cin.tie( nullptr );
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
    int t;
    //cin >> t;
    //for(int i=1; i<=t; i++)
    {
        Solve();
        cout << '\n';
    }
    return 0;
}
