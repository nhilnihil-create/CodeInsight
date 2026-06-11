#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    int A;

    std::cin >> N;
    vector<int> junban(N);

    for(int i = 0; i < N; i++){
        std::cin >> A;
        junban[A-1] = i + 1;
    }

    for(int i = 0; i < N; i ++){
        std::cout << junban[i] << " ";
    }
}