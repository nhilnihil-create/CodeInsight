#include<bits/stdc++.h>
#include<string>

using namespace std;

std::string S;

void solve (){
    if((S[2] == S[3]) && (S[4] == S[5])){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}


int main() {
    cin >> S;
    solve();
}