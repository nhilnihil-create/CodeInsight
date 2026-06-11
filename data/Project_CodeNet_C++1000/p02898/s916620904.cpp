#include <iostream>

using namespace std;

int main(void){
    int N, K;
    int x = 0;
    
    cin >> N >> K;
    
    for (int i = 0; i < N; i++)
    {
        int h;
        cin >> h;
        if (K <= h) {
            x++;
        }
    }
    cout << x;
}
