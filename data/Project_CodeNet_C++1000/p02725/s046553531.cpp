#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out, n) for(int i=0; i<n; i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    int k, n; cin>>k>>n;
    vector<int> a(n);
    vector<int> b(n);
    int sum=0;
    cin>>a[0];
    for(int i=1; i<n; i++){
        cin>>a[i];
        b[i]=a[i] - a[i-1];
        sum+=b[i];
    }
    b[0] = k-a[n-1] + a[0];
    sum += b[0];
    int ans=sum - *max_element(b.begin(), b.end());
    cout<<ans<<endl;
}