#include <bits/stdc++.h>
using namespace std;

#define ENDL '\n'
#define io ios_base::sync_with_stdio(false);cin.tie(0);
#define sayy cout<<"YES"<<ENDL;
#define sayn cout<<"NO"<<ENDL;

int gcd(int a, int b){
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

int main(){
    io

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i(0); i<n; i++){
        cin >> v.at(i);
    }

    int ans(0), brick(1);
    for(int i(0); i<v.size(); i++){
        if(v.at(i) != brick){
            ans++;
        }
        else{
            brick++;
        }
    }

    if(ans == n){
        cout << -1 << ENDL;
    }
    else{
        cout << ans << ENDL;
    }

    return 0;
}
