#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int * n_input = new int[n];
    for(int i = 0; i < n; i++) cin >> n_input[i];

    for(int i = n-1; i >= 0; i--) {
        cout << n_input[i];
        if(i != 0) cout << " ";
        else cout << endl;
    }

    delete[] n_input;
    return 0;
}