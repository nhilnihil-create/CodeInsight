#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    double x,y,z;
    double max=0;
    int L;cin>>L;
    L*=3;
    for(int x=0;x<=L;x++){
        for(int y=0;y<=L;y++){
            z=L-x-y;
            if(max<=x*y*z){
                max=x*y*z;
            }
        }  
    }
    max/=27;
    printf("%.12f",max);
}