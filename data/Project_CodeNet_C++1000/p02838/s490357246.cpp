#include<iostream>
#include<vector>
using namespace std;

static const long long MOD=1000000007;

int main(){
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    
    long long res=0;
    long long two_factor=1;
    for(int d=0;d<60;++d){
        long long zero=0,one=0;
        for(int i=0;i<n;++i){
            if(a[i]&(1LL<<d)) ++one;
            else ++zero;
        }
        long long temp = ((zero*one)%MOD)*two_factor%MOD;
        res=(res+temp)%MOD;
        two_factor=two_factor*2%MOD;
    }
    
    cout<<res<<endl;
}