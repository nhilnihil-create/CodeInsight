#include <iostream>

using namespace std;

int main() {
    int c = 0;
    string A, B;
    cin>> A;
    cin>> B;
    for(int i = 0; i < A.size(); i++)
        if(A[i] != B[i])
            c++;
    cout<< c;
    return 0;
}
