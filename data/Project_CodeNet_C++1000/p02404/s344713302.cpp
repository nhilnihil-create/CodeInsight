#include<iostream>
#define MAX_N 101


int main(){
        int H,W;
        char ch;
        while(1){
                std::cin>>H>>W;
                if(H==0 && W==0) break;
                for(int i=0;i<H;i++){
                        for(int j=0;j<W;j++){
                                if(i==0 || i==H-1) ch='#';
                                else if(j==0 || j==W-1) ch='#';
                                else ch='.';
                                 std::cout<<ch;
                        }
                        std::cout<<std::endl;
                }
                std::cout<<std::endl;
        }
        return 0;
}