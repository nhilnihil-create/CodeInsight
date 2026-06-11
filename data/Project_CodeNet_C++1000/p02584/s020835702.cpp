#include <bits/stdc++.h>
#define ll long long
using namespace std;

void testcase(){
    ll x,k,d;
    cin >> x >> k >> d;
    if(x<0) x*=-1;
    if(k>=x/d){
    k-= x/d;
    x%=d;
    if(k%2==0)
        cout << x;
    else
        cout << d-x;
    }
    else{
        cout << x-k*d;
    }

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q=1;
  //  cin >> q;
    while(q--){
    testcase();
    }
    return 0;
}

