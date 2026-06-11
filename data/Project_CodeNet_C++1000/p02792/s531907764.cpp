#include <bits/stdc++.h>
using namespace std;

int main() {
int ans = 0;
int N;
cin >> N;
vector<vector<int>> DP(9, vector<int>(9,0));
int digit = 1;
for (int i = 1; i <= N; i++){
    if (i == pow(10, digit)){
        digit += 1;
    }
    else if(i % 10 != 0){
        int x = i/pow(10, digit-1);
        int y = i % 10;
        DP.at(x-1).at(y-1)++;
    }
}

for (int i = 0; i < 9; i++){
    for (int j = i; j < 9; j++){
        if(i != j)ans = ans + 2 * DP.at(i).at(j) *DP.at(j).at(i);
        else ans = ans + DP.at(i).at(j) * DP.at(j).at(i);
    }
}

cout << ans << endl;
}