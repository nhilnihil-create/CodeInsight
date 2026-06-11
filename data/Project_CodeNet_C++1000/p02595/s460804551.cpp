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

int main(){
    int N,D;
    int X[MAX],Y[MAX];

    cin >> N >> D;
    for(int i = 0;i < N;i++){
        cin >> X[i] >> Y[i];
    }

    int ans = 0;

    for(int i = 0;i < N;i++){
        if(pow(X[i],2) + pow(Y[i],2) <= pow(D,2)){
            ans++;
        }
    }
    
    cout << ans << endl;

    return 0;
}