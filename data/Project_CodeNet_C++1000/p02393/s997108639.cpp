#include <iostream>

using namespace std;

int main(void)
{
    int data[3], temp;
    
    cin >> data[0] >> data[1] >> data[2];
    
    for (int i = 0; i < 2; ++i) {
        if (data[i] > data[i + 1]) {
            temp = data[i];
            data[i] = data[i + 1];
            data[i + 1] = temp;
        }
    }
    if (data[0] > data[1]) {
        temp = data[0];
        data[0] = data[1];
        data[1] = temp;
    }
    cout << data[0] << " " << data[1] << " " << data[2] << endl;   
    
    return 0;
}
