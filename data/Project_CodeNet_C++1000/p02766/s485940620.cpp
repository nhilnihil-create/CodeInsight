#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int min(int a,int b){
    return a<b?a:b;
}
int main(void){
    int N,K;
    cin >> N >> K;
    int i=0;
    while(N > 0){
        N /= K;
        i++;
    }
    cout << i;
}
