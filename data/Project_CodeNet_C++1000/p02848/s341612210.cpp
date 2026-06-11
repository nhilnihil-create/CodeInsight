#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;

    for(int i = 0; i < s.length(); i++){
        char k = s[i];
        int num = k - 'A';
        num += n;
        num %= 26;
        char nk = 'A' + num;
        cout << nk;
    }
    cout << endl;
    return 0;
}