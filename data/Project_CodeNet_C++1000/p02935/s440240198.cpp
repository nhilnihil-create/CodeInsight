#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    int n; cin>> n;
    vector<double> v(n);
    forin(v, n); sort(v.begin(), v.end());

    double ans=v[0];
    rep(i, n-1){
        ans = (ans + v[i+1])/2;
    }
    printf("%.8lf\n", ans);
}