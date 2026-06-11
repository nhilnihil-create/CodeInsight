//
//  main.cpp
//  B - Golden Coins
//
//  Created by 李远铄 on 2020/7/15.
//  Copyright © 2020 李远铄. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    long x;
    long ans=0;
    cin>>x;
    while (x/500!=0) {
        ans+=1000;
        x-=500;
    }
    while (x/5!=0) {
        ans+=5;
        x-=5;
    }
    cout<<ans;
    return 0;
}
