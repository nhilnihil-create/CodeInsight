//
//  main.cpp
//  B
//
//  Created by 曾憲揚 on 2020/8/21.
//  Copyright © 2020 曾憲揚. All rights reserved.
//

#include <iostream>
using namespace std;
int table[20], pre[20], prenonzer[20];

long long cal(int n){
    int cycs = (n+14)/15-1, mod = (n+14)%15 + 1;
    return pre[15]*cycs+ 1LL*(cycs-1)*cycs/2 * 15 * prenonzer[15]+
           pre[mod] + 1LL*15*cycs*(prenonzer[mod]);
}

int main(int argc, const char * argv[]) {
    for(int i=1; i<=15; i++){
        table[i] = (i%3==0 || i%5==0)? 0: i;
        prenonzer[i] = prenonzer[i-1] + bool(table[i]);
        pre[i] = pre[i-1] + table[i];
    }
    
    int n; cin>>n;
    cout<< cal(n) << '\n';
    return 0;
}
