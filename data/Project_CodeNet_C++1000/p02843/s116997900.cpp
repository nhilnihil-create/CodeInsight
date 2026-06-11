#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
int main() {
    int x;cin>>x;
    if(x>=2000) cout<<"1"<<endl;
    else{
        bool result=false;
        for(int i=1;i<22;i++){
            if(x>=100*i && x<=105*i) result=true;
        }
        if(result) cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }
}