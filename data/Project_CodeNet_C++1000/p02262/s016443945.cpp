#include <iostream>

int insertionSort(int *a, int n, int g){
    int tmp;
    int out_cnt = 0;
    for(int i = g; i < n; i++){
        tmp = a[i];

        int j = i;
        
        while(j-g >= 0 && a[j-g] > tmp){
            a[j] = a[j-g];
            j -= g;
            out_cnt++;
        }
        a[j] = tmp;
    }
    return out_cnt;
}

int main(){

    int n, tmp;
    std::cin >> n;

    int a[n];

    for(int i = 0; i < n; i++){
        std::cin >> tmp;
        a[i] = tmp;
    }

    int g[100];
    int max_g = 1;
    int m = 0;
    int cnt = 0;

    g[m] = 1;

    while(n > 3 * g[m] + 1){
        g[m+1] = 3 * g[m] + 1;
        m++;
    }

    std::cout << m + 1 << std::endl;

    for(int c = m; c >= 0; c--){
        if(c == 0){
            std::cout << g[c] <<std::endl;
        }else{
            std::cout << g[c] << " ";
        }
    }

    for(int i = m; i >= 0; i--){
        cnt += insertionSort(a, n, g[i]);
    }

    std::cout << cnt << std::endl;


    for(int i = 0; i < n; i++){
        std::cout << a[i] << std::endl;;
    }    

}
