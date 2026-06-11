#include <iostream>

int main(void){
    int N, fir=0, fir_i=0, sec=0, sec_i=0;
    std::cin >> N;
    for (int i=0; i<N; ++i){
        int tmp;
        std::cin >> tmp;
        if (tmp > fir){
            sec = fir;
            sec_i = fir_i;
            fir = tmp;
            fir_i = i;
        } else if (tmp > sec){
            sec = tmp;
            sec_i = i;
        }
    }

    for (int i=0; i<N; ++i){
        if (i != fir_i){
            std::cout << fir << std::endl;
        } else {
            std::cout << sec << std::endl;
        }
    }

    return 0;
}
