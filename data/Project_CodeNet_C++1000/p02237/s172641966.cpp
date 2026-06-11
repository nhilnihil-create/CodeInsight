#include <iostream>
using namespace std;
int main() {
    int num, num1, numb2, list1;
    cin >> num;
    int matrix[num][num] = {};
    for(int i = 0; i < num; i++) {
        cin >> num1 >> numb2;
        for(int i = 0 ; i < numb2; i++) {
            cin >> list1;
            matrix[num1 - 1][list1 - 1] = 1;
        }
    }
    for(int i = 0 ; i < num; i++) {
        for (int p = 0; p < num; p++) {
            if (p != num -1) {
                cout << matrix[i][p] << " ";
            } else cout<<matrix[i][p] << endl;
        }
    }
}
