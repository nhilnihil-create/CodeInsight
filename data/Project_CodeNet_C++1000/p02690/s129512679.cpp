#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int x;
    cin>>x;
    for(int i=-1000; i<=1000; ++i){
        for(int j=-1000; j<=1000; ++j){
            if((ll)i*i*i*i*i-(ll)j*j*j*j*j==x){
                cout<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }
}