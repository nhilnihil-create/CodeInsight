//
//  main.cpp
//  matrix-multiplication
//
//  Created by 黒田浩揮 on 2019/04/22.
//  Copyright © 2019 黒田浩揮. All rights reserved.
//

#include<iostream>
using namespace std;

long long numbers[101][101];
long long numbers2[101][101];
long long numbers3[101][101];

int main() {
    // insert code here...
    long long n,m,l,b,u;
    cin>>n>>m>>l;
    u=0;
    for (int v=0; v<n; v++) {
        for (int t=0; t<m; t++) {
            cin>>b;
            numbers[v][t]=b;
        }
    }
    for (int v=0; v<m; v++) {
        for (int t=0; t<l; t++) {
            cin>>b;
            numbers2[v][t]=b;
        }
    }
    for (int v=0; v<n; v++) {
        for (int t=0; t<l; t++) {
            u=0;
            for (int y=0; y<m; y++) {
                u+=numbers[v][y]*numbers2[y][t];
            }
            numbers3[v][t]=u;
        }
    }
    for (int v=0; v<n; v++) {
        for (int t=0; t<l; t++) {
            cout<<numbers3[v][t];
            if(t!=l-1)cout<<" ";else cout<<endl;
        }
    }
    
    
    return 0;
}

