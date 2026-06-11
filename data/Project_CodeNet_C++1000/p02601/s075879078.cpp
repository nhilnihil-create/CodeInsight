#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    int k;
    cin >> k;
    int d = 0;
    while (a>=b)
    {
        b=b*2;
        d++;
    }
    while (b>=c)
    {
        c=c*2;
        d++;
    }
    if(d<=k)cout << "Yes" <<endl;
    else cout << "No" <<endl;
}