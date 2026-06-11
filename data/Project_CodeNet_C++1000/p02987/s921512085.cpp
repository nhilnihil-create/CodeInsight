#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int N = S.size();
    map<char, int> M;
    for (int i = 0; i < N;i++)
    {
        M[S[i]]++;
    }
    for (int i = 0; i < N;i++)
    {
        if(M[S[i]] != 2){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}