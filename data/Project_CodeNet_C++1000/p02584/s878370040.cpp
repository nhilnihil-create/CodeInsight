#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    long long int x, k, d;
    cin >> x >> k >> d;
    long long int ans = x;

    if(x<0) x*=-1;

    if(k>=(x/d)){
        long long int temp = (x/d);
        x-=(x/d)*d;
        k-=temp;
    }else{
        x-=(k)*d;
        k=0;
    }

    if((k&1)==1){
        ans = abs(x-d);
    }else{
        ans=abs(x);
    }
    

    cout<<ans<<'\n';

    return 0;
}
