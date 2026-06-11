#include <iostream>
#include <array>

int main (){

    //data_set : a and b
    std::array<int, 4> data_a;
    std::array<int, 4> data_b;

    while(std::cin >> data_a[0] >> data_a[1] >> data_a[2] >> data_a[3]){
        std::cin >> data_b[0] >> data_b[1] >> data_b[2] >> data_b[3];
        int hit = 0;
        int blow = 0;
        for(int i = 0; i < 4; ++i){
            //if same digit and same num
            if(data_b[i] == data_a[i]) {
                hit++;
            } else {
                //if different digit and same num
                for (int j = 0; j < 4; ++j) {
                    if (data_b[i] == data_a[j]) {
                        blow++;
                    }
                }
            }
        }
        std::cout << hit << " " << blow << std::endl;

    }
}