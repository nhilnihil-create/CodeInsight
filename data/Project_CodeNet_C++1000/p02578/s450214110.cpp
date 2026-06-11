//  ⚫⚫ | ⚫➖➖ ⚫⚫ ⚫➖⚫⚫ ⚫➖⚫⚫ | ➖⚫⚫⚫ ⚫ | ⚫➖ | ⚫➖⚫ ⚫ ➖⚫⚫ | ➖⚫➖⚫ ➖➖➖ ➖⚫⚫ ⚫ ⚫➖⚫
#include<bits/stdc++.h>
#define n0_nnE int main(){
using namespace std;
typedef long long ll;
using namespace std;
 
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
 
    long long ans = 0;
    int MaxNum = 0;
    for (int i = 0; i < N; i++)
    {
        //Use common MaxNum to reduce the compuation time
        MaxNum = max(MaxNum, A[i]);
        int Bi = MaxNum;
        ans += Bi - A[i];
    }
 
    cout << ans << endl;
}