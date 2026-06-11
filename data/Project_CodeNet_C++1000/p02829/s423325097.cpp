//
//  main.cpp
//  vjudge
//
//  Created by Sudipto Mondal on 7/9/20.
//  Copyright © 2020 Sudipto Mondal. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    long long int a,b;
    cin>>a>>b;
    
    if((a+b)==3){
        cout<<"3"<<endl;
    }else if((a+b)==5){
        cout<<"1"<<endl;
    }else{
        cout<<2<<endl;
    }
    return 0;
}
