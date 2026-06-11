//
//  main.cpp
//  T2020B
//
//  Created by TakahiroUryu on 2020/06/15.
//  Copyright © 2020 TakahiroUryu. All rights reserved.
//

#include <iostream>
using namespace std;
using ll=long long;
int main(int argc, const char * argv[]) {
    ll a,v,b,w,t;
    bool ok=true;
    cin>>a>>v>>b>>w>>t;
    if (w>=v) {
        ok=false;
    } else {
        ll d=abs(a-b);
        ll s=v-w;
        if (d>s*t) {
            ok=false;
        }
    }
    if(ok){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
