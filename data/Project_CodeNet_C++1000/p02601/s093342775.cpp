#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

int main(){
    int A,B,C,K;
    bool ans = false;
    cin >> A >> B >> C >> K;

    for(int i = 0;i <= K;i++){
        if(A >= B){
            B *= 2;
        }else if(B >= C){
            C *= 2;
        }else{
            ans = true;
        }
    }

    if(ans)cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}