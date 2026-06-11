#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long l;
typedef long long unsigned ull;

ll nCr(int n,int r){
    long long p=1,k=1;


    if(n<r)
        return 0;

    if(n-r<r){
        r = n-r;
    }
    if(r!=0){
        while(r){
            p *= n;
            k *= r;

            ll m = __gcd(p,k);

            p /= m;
            k /= m;

            n--;
            r--;
        }
    }
    else
        p = 1;

    return p;
}

int main(){
    int n,m;
    cin>>n>>m;

    cout<<nCr(n,2)+nCr(m,2);

    return 0;

}
