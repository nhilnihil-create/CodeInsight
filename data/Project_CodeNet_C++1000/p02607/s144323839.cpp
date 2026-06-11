#include <iostream>
using namespace std;
const int Size = 105;
int Arr[Size];
int main()
{
    int N, c = 0; cin >> N;
    for (int i = 1; i <= N; i++){
        cin >> Arr[i];
        if (i%2 == 1 && Arr[i] % 2 == 1) c++;
    }
    cout << c << endl;
}
