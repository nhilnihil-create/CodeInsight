//                               //
    // author : samars_diary //
    // 18-09-2020 │ 19:55:52 //
//                               //

#include <iostream>
using namespace std;

void solve(){
    long long int a,b;
    cin>>a>>b;
    cout<<a*b;
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