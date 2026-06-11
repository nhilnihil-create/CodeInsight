
#include <iostream>
using namespace std;

int main()
{
    int N ,count=0;
    int a[100];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int i = 0;
    for (int i = 1; i <= N; i++) {
        
        if (i % 2 != 0) {
            if (a[i-1] % 2 != 0) {
                count += 1;
            }
            else {
                continue;
            }
        }
        if (i % 2 == 0) { continue; }
        
    }
    cout << count;
    return 0;
}