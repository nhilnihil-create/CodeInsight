#include<bits/stdc++.h>

#define ll long long

int main()
{
    int N, K;
    std::cin >> N >> K;

    std::map<int, int> data;

    for(int i=0; i < K; i++) {
        int a;
        std::cin >> a;
        for(int j=0; j < a; j++) {
            int value;
            std::cin >> value;
            data[value]++;
        }
    }

    int count = 0;
    for(int i=1; i <= N; i++) {
        if(data[i] == 0) {
            count++;
        }
    }

    std::cout << count << std::endl;
}