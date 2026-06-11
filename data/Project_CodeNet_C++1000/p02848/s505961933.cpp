#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    int len=S.size();
    for(int i=0; i<len; i++){
        int x=S.at(i)-'A';
        x=(x+N)%26;
        S.at(i)='A'+x;
    }
    cout << S << endl;
    
}
