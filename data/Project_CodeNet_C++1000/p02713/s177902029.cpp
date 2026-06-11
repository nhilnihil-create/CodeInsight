//
//  main.cpp
//  C
//
//  Created by 曾憲揚 on 2020/8/21.
//  Copyright © 2020 曾憲揚. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(a<b) swap(a,b);
    while(b>0){
        a%=b; swap(a,b);
    }
    return a;
}

int main(int argc, const char * argv[]) {
    int k; cin>>k;
    int ans=0;
    for(int a=1; a<=k; a++){
        for(int b=1; b<=k; b++){
            for(int c=1; c<=k; c++){
                ans+=gcd(gcd(a,b), c);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
