#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    double ans;
    if(n%2==0){
        ans = 0.5000000000;
    }
    else{
        ans=(n+1)/2.0/n;
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}