#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;



int main(){
    long long K;
    cin >> K;
    deque<long long> d;

    //init 
    for(int i=1; i<=9; ++i){
        d.emplace_back(i);
    }

    long long cnt = 0;

    while(true){
        cnt++;
        if(cnt == K) break;
        long long f = d.front();
        d.pop_front();
        long long new_num = 10*f + (f%10);

        if(new_num%10 != 0){
            d.emplace_back(new_num - 1);
        }
        d.emplace_back(new_num );
        if(new_num % 10 != 9){
            d.emplace_back( new_num + 1 );
        }

    }

    cout << d.front() << endl;
}