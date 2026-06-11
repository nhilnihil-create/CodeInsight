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
    int N;
    int A[MAX];

    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }

    long long ans = 0;
    int t = 0;
    for(int i = 0;i < N;i++){
        if(A[i] < t){
            ans += t - A[i];
            A[i] = t;
        }
        t = A[i];
    }

    cout << ans << endl;

    return 0;
}
