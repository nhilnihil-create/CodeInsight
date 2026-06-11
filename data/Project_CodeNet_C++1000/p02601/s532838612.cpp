#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i < (int)(n); i++)

int main() {
  int A, B, C, K;
    cin >> A >> B >> C >> K;
    bool flg = true;
    
   rep(i, K){
        if(A>=B) B *= 2;
        else if(B>=C) C *= 2;
    }
  	if(A<B && B<C) cout << "Yes" << endl;
    else cout << "No" << endl;
}
