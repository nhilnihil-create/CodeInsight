#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using P = pair<int, int>;
int main()
{
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    int cnt = 0;
    while(a >0){
        cnt++;
        a -= d;
    }
    if(c - b*cnt <= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}