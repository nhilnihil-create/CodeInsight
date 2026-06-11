//                               //
    // author : samars_diary //
    // 18-09-2020 │ 22:08:56 //
//                               //

#include <iostream>
using namespace std;

void solve(){
    long long int a ; cin>>a ;
    if(a%10==0 || a%10==1 || a%10==6 || a%10==8){
        cout<<"pon"<<'\n';
    }else if (a%10==3){
        cout<<"bon"<<'\n';
    }else{
        cout<<"hon"<<'\n';
    }
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