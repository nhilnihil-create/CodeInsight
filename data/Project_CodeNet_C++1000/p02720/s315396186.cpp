#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
    int K;
    cin >> K;
    deque<long long> d;
    for(int i = 1;i < 10;i++){
        d.push_back(i);
    }
    if(K < 10){
        cout << K << endl;
        return 0;
    }
    K -= 9;
    while (K){
        long long val = d.front();
        d.pop_front();
        for(int i = -1;i < 2;i++){
            long long next = val % 10 + i;
            if(next < 0 || next >9)
                continue;
            next = next + val *10;
            d.push_back(next);
            K--;
            if(K == 0){
                cout << d.back() << endl;
                return 0;
            }
        }
    }

}
