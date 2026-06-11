#include<bits/stdc++.h>
typedef  long long ll;
using namespace std;
ll maxi=1e18;


int main(){
    int n;cin>>n;
    ll x;
    long double zbr=1;
    for(int i=0;i<n;i++){
        cin >>x;
        if(zbr!=-1)
            zbr*=x;
        if(zbr>1000000000000000000  || zbr<0){
            zbr=-1;
        }
        if(x==0){
            zbr=0;
        }
    }
    cout << (ll)zbr<<endl;

}
