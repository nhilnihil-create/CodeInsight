#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    cin >> n;
    
    double aa,su;
    su=0;
    rep(i,n){
        cin >> aa;
        su+=1.0/aa;
    }


    printf("%.10f",1.0/su);
    
    

    return 0;
}