#include <bits/stdc++.h>
typedef long long ll;

using namespace std;


int main()
{
   string s;
   cin>>s;

    vector<int> cnt(2019,0);

    ll sum = 0, p =1;
    for(int i=s.size() - 1; i>=0; i--) {
        sum = ((s[i]-'0') * p + sum) % 2019;
        p = ( p*10 ) % 2019;
        cnt[sum]++;
    }

    ll ans = cnt[0];
    for(int i=0; i<2019; i++) {
        ans+= cnt[i] * (cnt[i]-1)  /2;

    }

    cout<<ans<<endl;


}
