#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    string S, T;
    std::cin >> N;
    vector<char> ans(2 * N);
    char c;
    for(int i = 0; i < N; i++){
        std::cin >> c;
        ans[0 + i * 2] = c;
    }

    for(int i = 0; i < N; i++){
        std::cin >> c;
        ans[1 + i * 2] = c;
    }

    for(int i = 0; i < ans.size(); i++){
        std::cout << ans[i];
    }

}