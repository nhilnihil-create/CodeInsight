//                               //
    // author : samars_diary //
    // 16-09-2020 │ 18:03:57 //
//                               //

#include <iostream>
using namespace std;

void solve(){
    long long int a;
    cin>>a;
    if(a==1){
        cout<<0;
    }else{
        cout<<1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int t = 1;
    while(t--){
        solve();
    }

    return 0;
}