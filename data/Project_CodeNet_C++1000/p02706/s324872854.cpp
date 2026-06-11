//
//  main.cpp
//  B
//
//  Created by 曾憲揚 on 2020/8/19.
//  Copyright © 2020 曾憲揚. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int maxM=1e4+4;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin>>n>>m;
    int a; int sum=0;
    for(int i=0; i<m; i++){
        cin>>a; sum+=a;
    }
    if(sum>n){
        cout<<-1<<endl;
    } else{
        cout<<n-sum<<endl;
    }
    return 0;
}
