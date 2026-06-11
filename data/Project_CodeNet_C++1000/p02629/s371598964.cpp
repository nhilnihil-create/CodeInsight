#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=1e6+5;
vector<ll> V;
int pre[maxn];
int main() {
    ll n;cin>>n;
    string s;
    while(n) {
    	s.push_back((n-1)%26+'a');
    	n=(n-1)/26;
    }
    for(int i=s.length()-1;i>=0;i--) cout<<s[i];
    return 0;
}