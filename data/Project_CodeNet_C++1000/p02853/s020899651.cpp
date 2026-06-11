#include <iostream>
using namespace std;

int score(int n) {
    if(n==1) return 300000;
    if(n==2) return 200000;
    if(n==3) return 100000;
    return 0;
}

int main(void){
    int A, B;
    cin >> A >> B;
    int sum = 0;
    sum += score(A);
    sum += score(B);
    if(sum == 600000) sum = 1000000;
    cout << sum << endl;
    return 0;
}
