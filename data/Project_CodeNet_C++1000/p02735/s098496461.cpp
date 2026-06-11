#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

int main(void){
    int h, w;
    std::cin >> h >> w;
    std::vector<std::vector<bool>> t1(h, std::vector<bool>(w));
    std::vector<std::vector<int>> t2(h, std::vector<int>(w));
    for(int i = 0; i < h; ++i){
        std::string tmp;
        std::cin >> tmp;
        for(int j = 0; j < w; ++j) t1[i][j] = tmp[j] == '.';
    }
    t2[0][0] = ((t1[0][0])? 0 : 1);
    for(int i = 1; i < h + w - 1; ++i){
        for(int j = 0; j <= i; ++j){
            if(j >= h || i - j >= w) continue;
            if(j > 0){
                if(i - j > 0){
                    if(t1[j][i - j]) t2[j][i - j] = std::min(t2[j - 1][i - j], t2[j][i - j - 1]);
                    else{
                        t2[j][i - j] = t2[j - 1][i - j] + ((t1[j - 1][i - j])? 1 : 0);
                        t2[j][i - j] = std::fmin(t2[j][i - j], t2[j][i - j - 1] + ((t1[j][i - j - 1])? 1 : 0));
                    }
                }
                else{
                    if(t1[j][i - j]) t2[j][i - j] = t2[j - 1][i - j];
                    else t2[j][i - j] = t2[j - 1][i - j] + ((t1[j - 1][i - j])? 1 : 0);
                }
            }else{
                if(t1[j][i - j]) t2[j][i - j] = t2[j][i - j - 1];
                else t2[j][i - j] = t2[j][i - j - 1] + ((t1[j][i - j - 1])? 1 : 0);
            } 
        }
    }
    std::cout << t2[h - 1][w - 1] << std::endl;

    return 0;
}