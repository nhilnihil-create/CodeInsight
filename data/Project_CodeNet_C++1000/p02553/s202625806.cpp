#include<bits/stdc++.h>
using namespace std;
long long a, b, c, d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    cin >> a >> b >> c >> d;
    cout << max(a * c, max(a * d, max(b * c, b * d))) << '\n';

    return 0;
}
