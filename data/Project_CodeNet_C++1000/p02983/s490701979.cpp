#include <bits//stdc++.h>
#define rep(i,n) for(int i = 0;i < n;i++)
using namespace std;
typedef long long ll;

int main(){
    ll l,r;
    cin>>l>>r;
    ll cnt=2019;
    bool t=false;
    for(ll i=0;i<r-l;i++){
        for(ll j=1;j<r-l+1;j++){
            if((l+i)*(l+j)%2019==0){
                cnt=0;
                t=true;
                break;
            }
            else{
                cnt=min((l+i)*(l+j)%2019,cnt);
            }
        }
        if(t)break;
    }
    cout<<cnt<<endl;
    return 0;
}