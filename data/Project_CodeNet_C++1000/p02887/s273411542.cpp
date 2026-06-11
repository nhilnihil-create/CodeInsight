#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    auto t = unique(S.begin(), S.end());
    S.erase(t, S.end());
    cout << S.size() << endl;
}