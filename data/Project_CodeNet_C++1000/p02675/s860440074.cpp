#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    if(N % 10 == 2 || N % 10 == 4 || N % 10 == 5 || N % 10 == 7 || N % 10 == 9) cout << "hon" << endl;
    else if(N % 10 == 0 || N % 10 == 1 || N % 10 == 6 || N % 10 == 8) cout << "pon" << endl;
    else if(N % 10 == 3) cout << "bon" << endl;

    return 0;
}