#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <climits>
int main(void){
    std::string S;
    std::cin >> S;
    long children[100000]={};
    long start=0,end=0;
    for(long i=0;i<S.length()-1;i++){
        if(S[i]=='R' && S[i+1]=='L'){
            int R_index=i;
            int L_index=i+1;
            while(S[i+1]=='L'){
                end=i+1;
                if(i<S.length()-1){i++;}else{
                    break;
                }
            }
            long children_num=end-start+1;
            if((R_index-start+1)%2==0){
                children[R_index]=children_num/2;
                children[L_index]=children_num-children_num/2;
            }else{
                children[R_index]=children_num-children_num/2;
                children[L_index]=children_num/2;                
            }
            start=i+1;
        }
    }
    for(long i=0; i<S.length();i++){
        std::cout << children[i];
        if(i!=S.length()-1){
            std::cout << " ";
        }else{
            std::cout << std::endl;
        }
    }
    return 0;
}