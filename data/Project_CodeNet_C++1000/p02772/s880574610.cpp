#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    bool is_approbed = true;
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        if(A%2 == 0) {
            if(A%3 != 0 && A%5 != 0) {
                is_approbed = false;
            }
        }
    }
    if(is_approbed) {
        cout << "APPROVED" << endl;
    } else {
        cout << "DENIED" << endl;
    }
    return 0;
}