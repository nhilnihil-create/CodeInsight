#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;
struct edge{ll x,y;};
struct huga{ll honest; bool done;};

int main(){
    int n;
    cin >> n;
    vector<int>s;
    ll a[n];
    ll all[60];
    ll bi[60];
    ll cu = 1;
    for(int i = 0; i < 60; i++){
        bi[i] = cu;
        cu *= 2;
        all[i] = 0;
    }
    for(int i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        vector<int>s;
        while(temp){
            s.push_back(temp%2);
            temp = temp / 2;
        }
    //reverse(begin(s),end(s));
        int nagasa = s.size();
        for(int i = 0; i < nagasa; i++){
            //all[i] = s[i];
            if(s[i] == 1){
                all[i]++;
            }
        }
    
    //a[i] = temp;
    }
    ll ans = 0;
    for(int i = 0; i < 60; i++){
        ll temp1,temp2;
        temp1 = all[i] * (n-all[i]) % mod;
        temp2 = bi[i] % mod;
        ans += temp1 * temp2 % mod;
      ans = ans % mod;
    }
    /*for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      ll temp = a[i] ^ a[j] ;//% mod;
    ans += temp;
    ans %= mod;
    }
    }*/

    cout << ans << endl;
}