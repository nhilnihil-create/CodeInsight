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

const int MAX = 200000;

int N,K;
int A[MAX];

bool check(int len){
    int c = 0;
    for(int i = 0;i < N;i++){
        c += (A[i] - 1) / len;
    }
    return c <= K;
}

int main(){
    cin >> N >> K;
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }

    int l = 1;
    int r = pow(10,9);
    int m = 0;
    int ans = pow(10,9);

    while(l < r){
        m = (l + r) / 2;
        if(check(m)){
            r = m;
            ans = min(ans,m);
        }else{
            l = m + 1;
        }
    }

    cout << ans << endl;

    return 0;
}