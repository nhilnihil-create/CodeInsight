#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;

ll cn[100010];

int main(){
    ll n;cin>>n;
    ll an=1;
    rep(i,0,n){
        ll a;
        cin>>a;
        if(a!=0){
            an=(an*(cn[a-1]-cn[a]))%1000000007;
        }
        cn[a]++;
    }
    if(cn[0]==1){
        an=(an*3)%1000000007;
    }
    else if(cn[0]>3){
        cout<<0<<endl;
        return 0;
    }
    else an=(an*6)%1000000007;
    cout<<an<<endl;
}





