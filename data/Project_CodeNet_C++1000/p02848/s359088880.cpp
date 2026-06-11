#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < s.size(); i++){
        if (s.at(i) + n <= 'Z') s.at(i) += n;
        else{
            int back = n - ('Z' - s.at(i)) -1;
            s.at(i) = 'A' + back;
        }
    }

    cout << s << endl;
}