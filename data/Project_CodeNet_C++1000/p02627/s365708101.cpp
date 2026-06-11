#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=1e6+5;
vector<ll> V;
int pre[maxn];
int main() {
    char buff[3];cin>>buff;
    if(*buff>='A'&&*buff<='Z') puts("A");
    else puts("a");
    return 0;
}