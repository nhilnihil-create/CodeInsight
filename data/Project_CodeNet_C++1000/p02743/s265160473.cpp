#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define rep(i, n) for (int i = 0; i < (n); i++)
using P=pair<int,int>;
int main() {
    ll a,b,c;cin>>a>>b>>c;
    if(c-a-b<=0){
        cout<<"No"<<endl;
    }else{
        if(c*c+a*a+b*b-2*a*b-2*a*c-2*b*c>0){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}
