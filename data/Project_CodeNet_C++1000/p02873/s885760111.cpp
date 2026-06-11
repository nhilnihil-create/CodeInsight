//
//  main.cpp
//  AGC_040_A
//
//  Created by Joe Mori on 2020/05/26.
//  Copyright © 2020 Joe Mori. All rights reserved.
//

#include <iostream>
#include<bits/stdc++.h>

int main(int argc, const char * argv[]) {
    std::string str;
    std::cin>>str;
    long long int sum=0;
    std::vector <int>vec(str.length()+1);
    vec.at(0)=0;
    for(int i=0;i<str.length();i++){
        if(str.at(i)=='<'){
            vec.at(i+1)=vec.at(i)+1;
        }
        //std::cout<<vec.at(i)<<std::endl;
    }
  //  std::cout<<"おわり"<<std::endl;
//    std::cout<<vec.at(str.length())<<std::endl;
    for(long long int i=str.size()-1;i>=0;i--){
        if(str.at(i)=='>'){
            vec.at(i)=std::max(vec.at(i+1)+1,vec.at(i));
        }
      //  std::cout<<vec.at(i)<<std::endl;
    }
    //std::cout<<vec.at(0)<<std::endl;
    for(int i=0;i<vec.size();i++){
        sum+=vec.at(i);
       // std::cout<<vec.at(i)<<std::endl;
    }
    std::cout<<sum<<std::endl;
   /* if(dai>shou){
        for(int i=0;i<=str.length();i++){
            str_min=std::min(str_min,vec.at(i));
            sum+=vec.at(i);
        }
        std::cout<<sum-str_min*(str.length()+1)<<std::endl;
    }else{
        for(int i=0;i<=str.length();i++){
            str_min=std::min(str_min,vec.at(i));
            sum+=vec.at(i);
        }
        std::cout<<sum-str_min*(str.length()+1)<<std::endl;
    }*/
   // for(int i=0;i<=str.length();i++)
//        std::cout<<vec.at(i)<<std::endl;
//    std::cout<<sum<<std::endl;
    return 0;
}
