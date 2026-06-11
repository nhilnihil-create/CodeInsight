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
    rep(i, 0, N) {
        cin>>s[i];
        sort(s[i].begin(), s[i].end());
    }
    sort(&s[0], &s[N]);
    ll ans=0;
    int i=0;
    while (i<N) {
        int j, k=1;
        for (j=i+1;s[i]==s[j];++j)++k;
        ans+=(ll)k*(ll)(k-1)/2;
        i=j;
    }
    cout<<ans<<endl;

}
int main()
{
    func();
}
