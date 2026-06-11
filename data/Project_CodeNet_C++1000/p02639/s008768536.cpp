#include <iostream>

using namespace std;

const int maxx = 5;
int x[maxx];

int main()
{
    for (int i = 0 ; i < 5 ; i++){
        cin >> x[i];
        if (x[i] == 0){
            cout << i + 1;
        }
    }
    return 0;
}
