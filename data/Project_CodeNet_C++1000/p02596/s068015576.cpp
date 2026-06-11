#include <iostream>

using namespace std;


int calc(int K){
    if( K < 0){return -1;}

    if( K % 2 == 0){ return -1; }

    

    int ans = 1; 
    unsigned long long sevens = 7;
    for( int i = 0; i <= K; i++){
        sevens = sevens % K;
        if( sevens == 0){ return ans;}

        ans++;
        sevens = sevens*10 + 7;
    }
    return -1;
};




int main(void){
    int K;
    cin >> K;

    int answer = calc(K);

    cout << answer;

}