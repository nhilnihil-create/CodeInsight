#include<bits/stdc++.h>
using namespace std;
int d, t, s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    cin >> d >> t >> s;
    if (t * s >= d) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
