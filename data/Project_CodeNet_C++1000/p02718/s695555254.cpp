#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out, n) for(int i=0; i<n; i++) cout<<out[i]<<endl
#define rep(i, a, n) for(int i=a; i<(n); i++)

int main(){
    int n, m; cin>>n>>m;
    int sum=0;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    if (sum % (4*m) ==0) sum /= 4*m;
    else sum = sum / (4*m) +1;
    rep(i, 0, m){
        if(a[i] < sum){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}