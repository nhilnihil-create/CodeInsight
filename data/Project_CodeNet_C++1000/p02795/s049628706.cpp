#include <iostream>
using namespace std;

int main()
{
    int H, W, N;
    cin >> H >> W >> N;
    if(H > W) {
        cout << (N/H)+((N%H==0)? 0 : 1) << endl;
    } else {
        cout << (N/W)+((N%W==0)? 0 : 1) << endl;
    }
    return 0;
}