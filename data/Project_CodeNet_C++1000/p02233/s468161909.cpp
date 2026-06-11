#include <iostream>
using namespace std;
int num;


int fib(int n, int array[]) {
    array[0] = 1;
    array[1] = 1;
    for (int i= 2; i <= n; i++) {
        array[i] = array[i - 1] + array[i - 2];
    }
    cout << array[n] << endl;
}
int main(void) {

    cin >> num;
    int array[num] = {};
    fib(num, array);


}
