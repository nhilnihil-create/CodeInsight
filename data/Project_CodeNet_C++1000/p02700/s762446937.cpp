
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define PI 3.14159265358979323846264338327950L

int a,b,c,d;

void solve(){

    cin >> a >> b >> c >> d;

    if(ceil((double)a/d) >= ceil((double)c/b)) cout << "Yes" << endl;
    else cout << "No" << endl;
}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}