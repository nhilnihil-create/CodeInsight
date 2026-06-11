#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    bool zoro = false;
    int count = 0;

    for(int i = 0; i < N; i++) {
        int D1, D2;
        cin >> D1 >> D2;
        if(D1 == D2) {
            count += 1;
            if(count >= 3) {
                zoro = true;
            }
        } else {
            count = 0;
        }
    }

    if(zoro) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}