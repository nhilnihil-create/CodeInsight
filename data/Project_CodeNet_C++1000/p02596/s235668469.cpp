//                               //
    // author : samars_diary //
    // 17-09-2020 │ 17:10:23 //
//                               //

#include <iostream>
#include <cmath>
using namespace std;

void solve(){
    long long int a;
    cin>>a;
    int val(7%a);
    for(int i=1; i<10000000; i++){
        if(val==0){
            cout<<i;
            return;
        }
        val=(val*10+7)%a;
    }
    cout<<-1;
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