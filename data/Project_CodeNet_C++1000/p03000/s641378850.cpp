#include <iostream>
using namespace std;
int main(void){
    int N, X;
    int D = 0;
    int bound = 1;
    cin >> N >> X;
    
    for (int i = 0; i < N; i++)
    {
        int l;
        cin >> l;
        if (D + l <= X) {
            ++bound;
            D = D + l;
        } else {
            break;
        }
    }
    cout << bound;
}
