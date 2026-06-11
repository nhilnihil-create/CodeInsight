#include <iostream>

int main(void){
    /* input */
    int beginNum  = 0;
    int endNum    = 0;
    int targetNum = 0;
    std::cin >> beginNum >> endNum >> targetNum;
    
    /* check */
    int count     = 0;
    for(int divideNum = beginNum; divideNum <= endNum; ++divideNum)
    {
        if((targetNum % divideNum) == 0)
        {
            ++count;
        }
    }
    /* output */
    std::cout << count << std::endl;
    
    return 0;
}