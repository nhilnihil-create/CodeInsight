#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main()
{
    int N;
    cin >> N;
    vector<int> input(N);
    vector<int> tmp(N);
    rep0(i,N){
        cin >> input[i];
        tmp[i] = input[i];
    }
    sort(input.begin(),input.end());
    int diff = 0;
    rep0(i,N){
        if(input[i]!=tmp[i]){
            diff++;
        }
    }
    if(diff<=2){
        cout << "YES";
    }else{
        cout << "NO";
    }
}
