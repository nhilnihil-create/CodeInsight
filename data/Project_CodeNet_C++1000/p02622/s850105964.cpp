#include <iostream>
#include <bits/stdc++.h>
const int Size = 200005;
long long Arr1[Size], Arr2[Size];
using namespace std;
int main()
{
    string S, T;
    cin >> S >>T;
    int c = 0;
    for (int i=0; i < S.length(); i++){
        if (S[i] != T[i]) c++;
    }
    cout <<c;
}
