#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    int n;
    cin >> n;
    int d[n + 5];
    for(int i = 0; i < n; i++)
        cin >> d[i];
    //1 4 4 5 5 9 14 14
    sort(d, d + n);
    cout << d[n/2] - d[(n/2) - 1];
    return 0;
}
