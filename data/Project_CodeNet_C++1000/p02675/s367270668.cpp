#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    if(N%10 == 2) cout << "hon";
    if(N%10 == 4) cout << "hon";
    if(N%10 == 5) cout << "hon";
    if(N%10 == 7) cout << "hon";
    if(N%10 == 9) cout << "hon";
    if(N%10 == 0) cout << "pon";
    if(N%10 == 1) cout << "pon";
    if(N%10 == 6) cout << "pon";
    if(N%10 == 8) cout << "pon";
    if(N%10 == 3) cout << "bon";
}