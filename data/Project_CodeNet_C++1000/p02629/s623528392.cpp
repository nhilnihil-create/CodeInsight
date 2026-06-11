#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long N;
    cin >> N;
    string letters = "0abcdefghijklmnopqrstuvwxyz";
    vector <char> S;
    while (N >= 1){
        long long mod = N % 26;
        if (mod == 0) {
            S.push_back('z');
            N--;
        }
        else S.push_back(letters[mod]);
        N /= 26;
    }
    for (int i = S.size()-1; i >=0; i--)
        cout << S[i];
    cout << endl;
}
