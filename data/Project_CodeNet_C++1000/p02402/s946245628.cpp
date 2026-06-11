#include <iostream>
using namespace std;

int main(void){
    long Num, Value, Min, Max, Sum;
    
    std::cin >> Num;
    
    Sum = 0;
    for(long i = 0; i < Num; i++){
        std::cin >> Value;
        if(i == 0){
            Min = Value;
            Max = Value;
        } else{
            if(Value < Min) Min = Value;
            if(Value > Max) Max = Value;
        }
        Sum += Value;
    }
    
    std::cout << Min << " " << Max << " " << Sum << std::endl;
}