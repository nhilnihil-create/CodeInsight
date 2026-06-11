#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    int k;
    cin>>k;
    vector<ll> a;
    for(int i=1;i<=9;i++) a.push_back(i);

    while(1){
        if(k<=(int)a.size()){
            cout<<a[k-1]<<endl;
            return 0;
        }
        k-=(int)a.size();
        vector<ll> v;
        swap(v,a);
        for(ll x : v){
            for(int i=-1;i<=1;i++){
                int d=x%10+i;
                if(d<0||d>9) continue;
                a.push_back(x*10+d);
            }
        }
    }
}