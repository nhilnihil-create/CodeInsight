#include <bits/stdc++.h>
using namespace std;

int main() {
    char C;
    cin >> C;
    vector<char> alp = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    for(int i=0;i<alp.size()-1;i++) {
        if(C==alp.at(i)) {
            cout << alp.at(i+1) << endl;
        }
    }
}