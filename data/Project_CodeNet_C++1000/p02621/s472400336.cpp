#include <bits/stdc++.h>
using namespace std;


int main(){

    int a, i=1, ans=0; cin >> a;
    for(i=1;i<=3;i++)
    {
        ans+=pow(a, i);
    }
    cout << ans;
    return 0;
}
