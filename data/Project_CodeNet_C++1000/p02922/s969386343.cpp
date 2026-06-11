#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B;
    cin >> A >> B;
    int count=0;
    int obj = 1;
    while(obj<B){
        obj--;
        obj+=A;
        count++;
    }
    cout << count << endl;
    return 0;
}