#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 300005;
const int mod = 998244353;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    vector<string>ans;
    int ptr = 1;
    ans.pb(s.substr(0,1));
    while(ptr < s.size()) {
        int cur = 1;
        while(ptr + cur <= s.size() && s.substr(ptr,cur) == ans.back()) {
            cur++;
        }
        if (ptr + cur > s.size())break;
        ans.pb(s.substr(ptr,cur));
        ptr += cur;
    }
    cout << ans.size() << '\n';
}