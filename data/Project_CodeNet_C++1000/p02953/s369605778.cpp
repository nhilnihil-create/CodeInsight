#include<iostream>
#include<math.h>
#include<cstring>
#include<vector>
#include<map>

typedef long long ll;
//sort(rt,rt+sizeof(rt)/sizeof(rt[0]),greater<>());
using namespace std;

#define rep(i,n) for(i=0;i<n;i++)



int main(){
    int i,n;
    cin>>n;
    ll dan[n];
    rep(i,n){
        cin>>dan[i];
    }
    if(n==1){
        cout<<"Yes";
        return 0;
    }
    for(i=n-1;i>0;i--){
        if(dan[i]>=dan[i-1]){
            ;
        }else if(dan[i]==dan[i-1]-1){
            dan[i-1]--;
        }else{
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}
