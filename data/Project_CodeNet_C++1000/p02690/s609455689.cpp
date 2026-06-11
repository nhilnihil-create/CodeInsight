#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int x;
    cin>>x;
    bool f=0;
    for(int i=-3000;i<=3000;i++){
        for(int j=-3000;j<=3000;j++)
        {
            if((i*i*i*i*i - j*j*j*j*j) == x)
            {
                f=1;
                cout<<i<<" "<<j<<endl;
                break;
            }
        }
        if(f)
            break;
    }
}