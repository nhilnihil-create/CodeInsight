#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n = s.size();
    unordered_map<int,int> m;
    m[0]++;
    int sum = 0;
    ll ans = 0;
    ll aux = 1;
    for(int i=n-1;i>=0;i--){
        int d = (int) s[i]-'0';
        sum = (sum + d*aux)%2019;
        aux = (aux * 10)%2019;
        ans +=  m[sum];
        m[sum]++;
    }
    cout<<ans<<"\n";
    return 0;

}


