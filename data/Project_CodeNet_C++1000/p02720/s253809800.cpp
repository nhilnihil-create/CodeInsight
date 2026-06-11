#include<iostream>
#include<vector>
#include<cmath>
#include<deque>
using namespace std;

long long mypow(long long x, long long y);

int main(){
    int K;
    long long count = 0;
    long long temp;
    int keta = 0;
    std::cin >> K;
    deque<long long> lunlun_list;

    //まず1~9までを格納
    for(int i = 1; i < 10; i++){
        lunlun_list.push_back(i);
    }

    while(1){
        temp = lunlun_list[0];
        lunlun_list.pop_front();
        count++;
        if(count == K){
            break;
        }

        if(temp%10 != 0){
            lunlun_list.push_back(temp * 10 + temp%10 -1);
        }
        lunlun_list.push_back(temp * 10 + temp%10);
        if(temp%10 != 9){
            lunlun_list.push_back(temp * 10 + temp%10 + 1);
        }
    }

    std::cout << temp;

    
}

long long mypow(long long x, long long y){
    long long ans = 1;
    for(long long i = 0; i < y; i++){
        ans = ans * x;
    }
    return ans;
}

