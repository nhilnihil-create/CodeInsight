#include <bits/stdc++.h>
using namespace std;
int main(void){
    string x;
    cin >> x;
    if(x[0] == '0'){cout << "Yes" << endl; return 0;}
    int sum = 0;
    for (int i = 0; i < x.length(); ++i){
        sum += x[i]-'0';
    }
    if(sum%9 == 0){cout << "Yes" << endl;}
    else{std::cout << "No" << std::endl;}
    return 0;
}
