#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    map <string, int> A;
    for (int i=0; i<N; i++){
        string s;
        cin >> s;
        if (A.count(s)){
            A[s]++;
        }
        else {
            A[s]=1;
        }
    }
    int count=0;
    cout << A.size() << endl;
}