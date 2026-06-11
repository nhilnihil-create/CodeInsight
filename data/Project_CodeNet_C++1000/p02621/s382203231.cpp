#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=1e6+5;
vector<ll> V;
int pre[maxn];
int main() {
	int a;cin>>a;
	cout<<a*(1+a*(1+a))<<endl;    
    return 0;
}