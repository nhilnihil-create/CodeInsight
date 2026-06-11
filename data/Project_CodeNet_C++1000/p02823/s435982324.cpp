#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long int N, A, B;
    cin >> N >> A >> B;
    
    if((B-A)%2) {
        cout << min((N-B+N-A+1)/2, (A-1+B)/2) << endl;
    } else {
        cout << (B-A)/2 << endl;
    }


    return 0;
    
}