#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,a,b) for (int i=a; i<b; ++i)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string S; cin >> S;
    ll N=S.length();
    reverse(S.begin(),S.end());
    vector <ll> rem(N);
    rem[0]=(S[0]-'0')%2019;
    ll pow10=10;
    for (int i=1; i<N; ++i) {
        rem[i]=(pow10*(S[i]-'0')+rem[i-1])%2019;
        pow10*=10;
        pow10%=2019;
    }
    map <ll, ll> count;
    ll ans=0, currem=0;
    for (auto x: rem) count[x]++;
    // for (auto x: rem) cout << x << " "; cout << "\n";
    pow10=1;
    for (int i=0; i<N; ++i)
    {
        ans+=count[currem];
        currem+=pow10*(S[i]-'0');
        currem%=2019;
        pow10*=10;
        pow10%=2019;
        count[rem[i]]--;
    }
    cout << ans << "\n";
    return 0;
}