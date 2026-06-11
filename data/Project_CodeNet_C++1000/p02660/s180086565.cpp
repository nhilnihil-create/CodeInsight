#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array


ll n;
ll ans = 0;


ll combis(int x){
    
    ll ret = 0;

    ll i = 1;
    ll b = 2;
    while (i <= x)
    {
        i = i+b;
        b++;
        ret++;
    }
    
    return ret;
}

void solve(){

    cin >> n;

    
    ll tmp = sqrt(n)+1;

    ll pow = 0;

    while(n % 2 == 0){
        n /=2;
        pow +=1;
    }
    ans += combis(pow);

    for (int i = 3; i < tmp; i = i+2)
    {
        pow = 0;
        while(n % i == 0){
            n /=i;
            pow +=1;
            //cout << "i :" << i << "  pow = " << pow << endl;
        }
        
        if(pow >0){
            //cout << "combis : " << combis(pow) << endl;
            ans += combis(pow);
        } 

        if(n == 1){
            break;
        } 
    }
    if(n != 1){
        ans ++;
    }
        cout << ans << endl;

    
}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}