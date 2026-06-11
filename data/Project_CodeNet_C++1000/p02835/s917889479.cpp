#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
    long long A,B,C;
    cin>>A>>B>>C;

    if(22<=A+B+C)cout<<"bust";
    else cout<<"win";
    return 0;
}