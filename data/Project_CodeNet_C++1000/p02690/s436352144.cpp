#include<iostream>

void correct(){
    int X;
    std::cin>>X;
    for(int A=-118;A<120;++A){
        for(int B=-119;B<118;++B){
            if(A*A*A*A*A-B*B*B*B*B==X){
                std::cout<<A<<" "<<B<<std::endl;
                return;
            }
        }
    }
}
int main(){
    correct();
}