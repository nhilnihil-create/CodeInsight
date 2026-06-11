#include<iostream>
#include<vector>
using namespace std;

int main(){
    int ans = 0;
    int N;

    std::cin >> N;
    vector<int> tako(N);

    for(int i = 0; i < N; i++){
        std::cin >> tako[i];
    }

    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            ans = ans + tako[i]*tako[j];
        }
    }

    std::cout << ans;


}