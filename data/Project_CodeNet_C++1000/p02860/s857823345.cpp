#include <iostream>

#define endl '\n'
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void solve()
{
    int n;
    string s;

    cin >> n >> s;

    if(n % 2 != 0)
        cout << "No";
    else
    {
        string a(s, 0, n/2);
        string b(s, n/2);

//        cout << a << "--" << b << endl;

        if(a == b)
            cout << "Yes";
        else
            cout << "No";
    }


}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

//    int t; cin >> t; while(t--){
        solve();
//    }
    return 0;
}
