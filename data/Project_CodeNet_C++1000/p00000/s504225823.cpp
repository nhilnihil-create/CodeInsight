//
//  main.cpp
//  sanpie
//
//  Created by h3037178 on 2017/07/28.
//  Copyright ?? 2017??´ ?????£?????????. All rights reserved.
//

#include <iostream>
using namespace std;
int main(){
    int i,o,s;
    for(i=1;i<=9;i++){
        for(o=1;o<=9;o++){
            s=i*o;
            cout<<i<<"x"<<o<<"="<<s<<endl;
        }
    }
}