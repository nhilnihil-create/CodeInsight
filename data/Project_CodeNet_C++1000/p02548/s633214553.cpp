#include <iostream>
#include <string>
using namespace std;
#define N_MAX 1000000

int N;

int input(){
    cin >> N;
    return 0;
}

// int solve(){
//     long long count_total = 0;
//     // long long memo[N_MAX];
//     // memo[1]=1;
//     for (int c=1;c<N;c++){
//         // N-cの約数の数を求める
//         int count=0; 
//         for (int a=1;a<=N-c/2+1;a++){
//             if ((N-c)%a==0){
//                 count++;
//             }
//         }
//         count

//     }
//     cout << count_total << endl;
//     return 0;
// }

int solve(){
    int count = 0;
    for (int a=1;a<=N-1;a++){
        count += (N-1)/a;
    }
    cout << count << endl;
    return 0;
}

int main(){
    input();
    solve();
    return 0;
}