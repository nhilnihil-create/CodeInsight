#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out, n) for(int i=0; i<n; i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)
int main(){
    int n; cin>>n;
    vector<int> x(n);
    vector<int> y(n);
    forin(x, n);
    forin(y, n);
    vector<int> z;
    z=x;
    sort(z.begin(), z.end());

    int cntx=1;
    int cnty=1;
    int a, b;
    int jx=0, jy=0;
    do{
        rep(i, n){
            if(x[i]==z[i]) jx++;
            if(y[i]==z[i]) jy++;
        }
        if(jx==n) a=cntx;
        else cntx++;
        if(jy==n) b=cnty;
        else cnty++;
        jx=0;
        jy=0;
    }while(next_permutation(z.begin(), z.end()));

    cout<<abs(a-b)<<endl;
}