#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1000000000000
#define MOD 1000000007

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(15);

    ll h,w;
    cin>>h>>w;
    if(h==1 || w==1){
        cout<<1<<endl;
    }else{
        cout<<(h*w+1)/2<<endl;
    }
    return 0;
}