#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <iomanip>
#include <valarray>
#include <vector>


int main(int argc, char *argv[])
{
    std::cout << std::fixed << std::setprecision(0);
    int h,w;
    while(1){
        std::cin >> h >> w;
        if(h+w == 0)break;

        std::string out = "";
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                out += "#";
            }
            out += "\n";
        }
        std::cout << out << std::endl;
    }

    return 0;
}