#include <iostream>
using namespace std;
int num;

int main(void) {
    cin >> num;
    int array[num] = {};
    array[0] = 1;
    array[1] = 1;
    for (int i= 2; i <= num; i++) {
        array[i] = array[i - 1] + array[i - 2];
    }
    cout << array[num] << endl;
}


