#include <iostream>
using namespace std;

int main()
{
    int N, count = 0;
    int a[100];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i<N; i++) {

        if (i % 2 == 0 && a[i] % 2 != 0) {

            count += 1;
        }


    }
    cout << count;
    return 0;
}