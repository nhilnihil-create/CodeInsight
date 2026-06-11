#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int youbi(string S) {
    if (S == "SUN") return 0;
    else if (S == "MON") return 1;
    else if (S == "TUE") return 2;
    else if (S == "WED") return 3;
    else if (S == "THU") return 4;
    else if (S == "FRI") return 5;
    else if (S == "SAT") return 6;
    else return -1;
}

int main(){ 
    string S;
    cin >> S;
    cout << 7 - youbi(S) << endl;
    
}


