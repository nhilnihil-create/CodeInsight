//                               //
    // author : samars_diary //
    // 17-09-2020 │ 07:54:55 //
//                               //

#include <iostream>
#include <cmath>

using namespace std;

void solve(){
    int a; cin>>a;
    cout<<1000*ceil(a/1000.0)-a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif

    int t = 1;
    while(t--){
        solve();
    }

    return 0;
}