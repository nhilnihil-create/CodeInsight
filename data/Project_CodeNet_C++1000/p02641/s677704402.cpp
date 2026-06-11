#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e6+5;
std::map<int,int> M;
int main() {
    int x,n;cin>>x>>n;
    for(int i=1;i<=n;i++) {
    	int tem;cin>>tem;M[tem]=1;
    }
    int ans=-100;
    for(int i=-100;i<=1000;i++) {
    	if(M[i]) continue;
    	if(abs(x-i)<abs(x-ans)) ans=i; 
    }
    cout<<ans<<endl;
    return 0;
}