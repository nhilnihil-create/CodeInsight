#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

int main()
{
    int X, N;
    std::cin >> X >> N;

    std::vector<int> data(N);
    for(int i=0; i < N; i++) {
        std::cin >> data[i];
    }

    // 昇順にソート
    std::sort(data.begin(), data.end() );

    int start = 0;
    int end = N-1;
    int point = -1;
    
    // 二分探索
    while(start <= end) {
        int middle = (start + end) / 2;
        if(X == data[middle]) {
            point = middle;
            break;
        }
        else if(X > data[middle]) {
            start = middle + 1;
        }
        else {
            end = middle - 1;
        }
    }

    if(point == -1) {
        std::cout << X << std::endl;
    }
    else if(point == 0) {
        std::cout << X-1 << std::endl;
    }
    else {
        int point_minus = point-1;
        int point_plus = point+1;
        int value_minus = X-1;
        int value_plus = X+1;

        while(true) {
            if(point_minus < 0) {
                std::cout << value_minus << std::endl;
                break;
            }
            if(point_plus > (N-1)) {
                if(data[point_minus] == value_minus) {
                    std::cout << value_plus << std::endl;
                    break;
                }
                else {
                    std::cout << value_minus << std::endl;
                    break;
                }
            }

            if(data[point_minus] != value_minus) {
                std::cout << value_minus << std::endl;
                break;
            }
            else {
                point_minus--;
                value_minus--;
            }

            if(data[point_plus] != value_plus) {
                std::cout << value_plus << std::endl;
                break;
            }
            else {
                point_plus++;
                value_plus++;
            }
        }
    }
}