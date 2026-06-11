#include <iostream>
using namespace std;

// Caleb Faith Adnaka XI105
int main() {

    int N,R;
    cin >> N;
    cin >> R;

    if (N >= 10){
        cout << R << "\n";
    }
    else{
        cout << R + (100 * (10-N)) << "\n";
    }

}
