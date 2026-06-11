
#include <iostream>
using namespace std;

int main(){
    int D, T, S;
    cin >> D >> T >> S;
    if (S*T >= D) cout << "Yes";
    if (S*T < D) cout << "No";
    cout << "\n";
}

