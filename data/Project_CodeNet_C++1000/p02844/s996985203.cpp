//
//  main.cpp
//  Mitusi_2019_D
//
//  Created by Joe Mori on 2020/06/29.
//  Copyright © 2020 Joe Mori. All rights reserved.
//

#include <iostream>
#include<string>
int main() {
    // insert code here..;
    int n,ans=0;
    std::string str;
    std::cin>>n>>str;
    int count=0;
    for(int j=0;j<10;j++){
        for(int k=0;k<10;k++){
            for(int l=0;l<10;l++){
                for(int i=0;i<n;i++){
//                    std::cout<<"i:"<<str[i]-'0'<<" j:"<<j<<" k:"<<k<<" l:"<<l<<std::endl;
                   // std::cout<<j*100+k*10+l<<std::endl;
                    if(str[i]-'0'==j&&count==0){
                        count++;
                        continue;
                    }
                    if(str[i]-'0'==k&&count==1){
                        count++;
                        continue;
                    }
                    if(str[i]-'0'==l&&count==2){
                        count++;
                    }
                    if(count==3){
                        ans++;
                        count=0;
                        break;
                    }
                    if(i==n-1||(i==n-2&&count==1)||(i==n-3&&count==0)){
                        count=0;
                        break;
                    }
                }
//                std::cout<<"ans:"<<ans<<std::endl;
            }
        }
    }
    std::cout<<ans<<std::endl;
    return 0;
}
