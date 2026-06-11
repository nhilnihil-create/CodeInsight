#include <bits/stdc++.h>
#define ll uint64_t
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <ll, ll>
#define vii vector <ii>
#define graph vector <set <int> >
#define inf 1000000000
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
    int n;
    cin >> n;
    int in;
    int cont = 1;
    int ans = 0;
    while (n--) {
        cin >> in;
        if (in % 2 && cont % 2) ans++;
        cont++;
    }
    cout << ans << endl;
    return 0;
}