#include <iostream>
 
void show_ret(int home[][10], bool use_partition) {
    for(int i= 0; i < 3; i++) {
        for(int j = 0; j < 10; j++) {
            std::cout << " " << home[i][j];
        }
        std::cout << std::endl;
    }
    if(use_partition) std::cout << "####################" << std::endl;
}

int main(int argc, char *argv[]) {
    int home1[3][10] = {{0}};
    int home2[3][10] = {{0}};
    int home3[3][10] = {{0}};
    int home4[3][10] = {{0}};
    int n, b, f, r, v = 0;
 
    std::cin >> n;      
    for(int i = 0; i < n; i++) {
        std::cin >> b >> f >> r >> v;
        switch(b) {     
            case 1:     
                home1[f-1][r-1] += v;
                break;  
            case 2:     
                home2[f-1][r-1] += v;
                break;  
            case 3:     
                home3[f-1][r-1] += v;
                break;  
            case 4:     
                home4[f-1][r-1] += v;
                break;  
        }
    }
    show_ret(home1, true);
    show_ret(home2, true);
    show_ret(home3, true);
    show_ret(home4, false);
    return 0;
}