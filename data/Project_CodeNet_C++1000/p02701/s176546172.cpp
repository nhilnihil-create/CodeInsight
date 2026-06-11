#include<map>
#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int N;
    string item;
    std::map<string, int> mp;
    scanf("%d", &N);
//   printf("%d", N);

    for(int i = 0; i < N; i++){
        std::cin >> item;
        mp[item] = 1;
    }

    printf("%d", (int)mp.size());

}