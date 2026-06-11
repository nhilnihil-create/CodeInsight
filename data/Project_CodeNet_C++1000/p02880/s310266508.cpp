#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n , i;
    cin>>n;

    bool ok = 0;

    for(i = 9 ; i >= 1 ; i--){
        if(n%i == 0){
            int ans = n/i;
            //cout<<ans<<endl;
            if(ans >= 1 && ans <= 9){
                ok = 1;
                break;
            }
        }
    }

    if(ok) cout<<"Yes\n";
    else cout<<"No\n";

    return 0;
}
