#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(std::string S){
    vector<string> T ={"Sunny","Cloudy","Rainy"};
    for(int i=0;i<3;i++){
        if(T[i] == S){
            cout << T[(i+1)%3] << endl;
            return;
        }
    }
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
