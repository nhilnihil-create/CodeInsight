#include <iostream>
#include <string>

using namespace std;

int main () {
    string T, S;
    int count = 0, i;
    cin >> S;
    while(cin >> T, T != "END_OF_TEXT") {
        for (i=0;i < T.size(); i++) {
            if(T[i]>= 'A' && T[i] <= 'Z')
                T[i] += 32;
        }
        if(T == S)
            count++;
    }
    cout << count << endl;
}