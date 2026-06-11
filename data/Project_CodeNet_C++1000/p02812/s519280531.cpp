#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    
    int sum = 0;
    rep(i, n - 2) {
        if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
            sum += 1;
        }
    }
    println(sum)
    return 0;
}