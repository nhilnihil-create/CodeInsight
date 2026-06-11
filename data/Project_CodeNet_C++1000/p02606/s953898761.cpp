//Author rahuliitkgp

/*A thing of beauty is a joy forever,
Its loveliness increases,
it will never pass into nothingness.*/
//Men at Work :)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int ll;

#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(x)            int x; cin>>x; while(x--)
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void cpp(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int main(){
    cpp();
    ll l ,r ,d;
    cin>>l>>r>>d;
    ll ans = 0;
    for(ll i=l; i<=r; i++){
        if(i%d==0) ans++;
    }
    cout<<ans<<endl;
    return 0;
}



