#include <bits/stdc++.h>
using namespace std;


void solve(std::string S){
    if (S == "Sunny") cout << "Cloudy" << endl;
    else if (S == "Cloudy") cout << "Rainy" << endl;
    else if (S == "Rainy") cout << "Sunny" << endl;
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
