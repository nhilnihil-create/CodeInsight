#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int main(){
    LL x;double y;
    cin>>x>>y;

    y*=100;

    LL z=y;

    for(int i=-1;i<=1;++i){
        if(fabs((z+i)-y)<fabs(z-y)){
            z+=i;
        }
    }


    cout<<x*z/100;
    return 0;
}

