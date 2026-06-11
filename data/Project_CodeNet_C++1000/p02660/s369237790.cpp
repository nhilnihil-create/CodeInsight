#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
int res(ll n){
    int ans =0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            int fac =0;
            while(n%i==0){
                n/=i;
                fac++;
            }
            ans+=(sqrt(8*fac+1)-1)/2;

        }
    }
    if(n>1) ans++;
    return ans;
}
int main(){
    ll n;
    cin >> n;
    cout << res(n) << endl;
}
