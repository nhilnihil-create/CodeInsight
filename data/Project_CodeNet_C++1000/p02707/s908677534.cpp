//
//  main.cpp
//  C
//
//  Created by 曾憲揚 on 2020/8/19.
//  Copyright © 2020 曾憲揚. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int o[maxn];


int main(int argc, const char * argv[]) {
    int n; cin>>n;
    
    int a;
    for(int i=1; i<n; i++){
        cin>>a; o[a]++;
    }
    for(int i=1; i<=n; i++){
        cout<<o[i]<<" ";
    }
    cout<<endl;
    return 0;
}
