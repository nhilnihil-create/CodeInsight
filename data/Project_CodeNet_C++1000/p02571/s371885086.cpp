#include <iostream>
#include <climits>
using namespace std;

int main(){
    string S, T;
    cin >> S >> T;
    int smallest = INT_MAX;
    for (int i = 0; i < S.length() - T.length() + 1; ++i){
        int unmatched = 0;
        for (int j = 0; j < T.size(); ++j){
            if (T[j] != S[j + i]) ++unmatched;
        }
        smallest = min(smallest, unmatched);
    }
    cout << smallest << "\n";
}
