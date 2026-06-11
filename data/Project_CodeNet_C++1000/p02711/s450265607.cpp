//
//  main.cpp
//  A
//
//  Created by 曾憲揚 on 2020/8/21.
//  Copyright © 2020 曾憲揚. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    int n; cin>>n;
    for(int i=0; i<3; i++){
        if(n%10 == 7){
            cout<<"Yes\n"; return 0;
        }
        
        else n/=10;
    }
    cout<<"No\n";
    return 0;
}
