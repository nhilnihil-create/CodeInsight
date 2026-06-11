//                               //
    // author : samars_diary //
    // 16-09-2020 │ 18:15:57 //
//                               //

#include <iostream>
using namespace std;

void solve(){
    long long int a,b,c,d;
    cin>>a>>b>>c>>d;
    long long int p = max(max(a,b)*max(c,d),min(a,b)*min(c,d));
    long long int q= max(min(a,b)*max(c,d),max(a,b)*min(c,d));
    cout<<max(p,q);
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