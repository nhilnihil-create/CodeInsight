#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, M;
void func()
{
    cin>>N;
    string s[N];
    map<string, int> a;
    ll ans=0;
    rep(i, 0, N) {
        cin>>s[i];
        sort(s[i].begin(), s[i].end());
        if (a.count(s[i])==0)a[s[i]]=1;
        else {
            ans+=a[s[i]];
            ++a[s[i]];
        }
    }
    cout<<ans<<endl;

}
int main()
{
    func();
}