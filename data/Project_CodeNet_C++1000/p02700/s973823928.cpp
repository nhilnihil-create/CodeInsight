#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int turn=0;
    while(A>0 && C>0){
        if(turn%2==0) C-=B;
        else A-=D;
        turn++;
    }

    if(A<=0) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}