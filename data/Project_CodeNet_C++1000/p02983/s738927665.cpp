#include<iostream>
#include<cmath>
using namespace std;
using ll=long long;

int main(){
    ll L,R;
    cin>>L>>R;
    int a[2019];
    for(ll i=0;i<2019;i++){
        a[i]=0;
    }
    for(ll i=L;i<=R;i++){
        ll temp=i%2019;
        if(temp==0){
            cout<<0<<endl;
            return 0;
        }
        a[temp]++;
    }
    ll min_value=2020;
    for(ll i=0;i<2019;i++){
        for(ll j=0;j<2019;j++){
            if(i==j){
                if(a[i]>=2){
                    min_value=min(min_value,i*j%2019);
                }
            }else if(a[i]>=1&&a[j]>=1){
                min_value=min(min_value,i*j%2019);
            }
        }
    }
    cout<<min_value<<endl;
    return 0;
}