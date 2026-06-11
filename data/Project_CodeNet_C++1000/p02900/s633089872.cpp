#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using ll=long long;
int main() {
    ll A,B; cin>>A>>B;
    if(A>B)swap(A,B);
    int div=2;
    int ans=1;
    int prev=1;
    int upper=floor(sqrt(A));
    while(div<=upper){
        if(A%div==0){
            A/=div;
            if(B%div==0 && div!=prev)ans++;
            prev=div;
        }else{
            div++;
        }
    }
    if(A>1 && B%A==0)ans++;
    cout<<ans<<endl;
}