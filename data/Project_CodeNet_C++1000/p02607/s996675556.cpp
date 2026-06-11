#include <iostream>

using namespace std;

int main()
{

    int n;  cin >> n;
    int numOdd = 0;
    int* arr = new int[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] % 2 != 0 && i % 2 == 0){
            numOdd++;
        }
    }

    cout << numOdd << endl;

    return 0;
}
