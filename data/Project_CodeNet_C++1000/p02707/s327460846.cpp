#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main(){
    int N, hito, count;

    std::cin >> N;
    std::vector<int> syain(N);
    std::vector<int> numbers(N, 0);
    syain[0] = 0;

    for(int i = 1; i < N; i++){
        scanf("%d", &syain[i]);
    }

    for(int i = 1; i < N; i++){
        numbers[syain[i]-1]++;
    }
    
    for(int i = 0; i<N; i++){
        printf("%d\n", numbers[i]);
    }
    
}