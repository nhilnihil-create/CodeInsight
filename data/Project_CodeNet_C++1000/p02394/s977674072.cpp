#include <iostream>
#include <cmath>

bool checkInputParameter(const int& val, bool isCircle) {
    if(isCircle) {
        if ((-100 <= val) && (val <= 100)) {
            return true;
        }
        return false;
    }
    
    if ((0 < val) && (val <= 100)) {
        return true;
    }
    return false;
}

int main(int argc, char* argv[])
{
    int W, H, x, y, r;
    
    std::cin >> W;
    std::cin >> H;
    std::cin >> x;
    std::cin >> y;
    std::cin >> r;
    
    if (!checkInputParameter(W, false)
     || !checkInputParameter(H, false)
     || !checkInputParameter(x, true)
     || !checkInputParameter(y, true)
     || !checkInputParameter(r, false))
        goto END;
    
    if (((x-r) >= 0)
     && ((x+r) <= W)
     && ((y-r) >= 0)
     && ((y+r) <= H)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    
END:
    return 0;
}
