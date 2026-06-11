
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
 
#define rep(i,n) for(ll i=0;i<(n;i++)
typedef long long ll;
using namespace std;

int main(void){
    int A,B,C,K;
    cin >> A >> B >> C >> K;
    while(B<=A){
        B *= 2;
        K--;
    }
    while(C<=B){
        C *= 2;
        K--;
    }
    if(K<0){
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
}
    