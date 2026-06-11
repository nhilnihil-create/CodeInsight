#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef long long ld;

int main() {
	ll n;
    cin>>n;
    vector<ll>rta(n+1,0);
    vector<ll>a(n,0);
    ll tmp;
    for (int i=0; i<n; i++){
        cin>>tmp;
        a[i]=tmp;
        rta[tmp]++;
    }
     tmp=0;
    for (int i=0; i<n; i++){
        tmp+=(rta[i+1]*(rta[i+1]-1))/2;
    }
    for (int i=0; i<n; i++){
        cout<<tmp-rta[a[i]]+1<<endl;
    }
}