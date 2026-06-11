#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n,l;
    cin >> n >> l;
    int s;
    s=n*l+(n-1)*n/2;

    if(l>=0){
        s-=l;
    }
    else if(l+n-1<=0){
        s-=(l+n-1);
    }
    
    cout << s << endl;
    

    return 0;
}