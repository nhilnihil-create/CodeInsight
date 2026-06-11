// mod 組み合わせ計算2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)


int main(){
    double a,b,x;
    cin>>a>>b>>x;
    double l=a*a*b/2;
    double dd;
    if(a*a*b==x){
        cout<<"0"<<endl;return 0;
    }
    if(l==x){
        dd=atan(a/b);
    }
    else if(x<l){
        dd=atan(2*x/a/b/b);
    }
    else{
        dd=atan(a*a*a/2/(a*a*b-x));
    }
    double ans=(M_PI/2-dd)*180/M_PI;
    std::cout << std::fixed<<std::setprecision(9);
    cout<<ans<<endl;
    return 0;
}
