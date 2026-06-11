#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <algorithm>

int main(){

    int N; cin>>N;
    vector<int> P(N), Q(N);
    for (int n=0; n<N; n++) cin>>P[n];
    for (int n=0; n<N; n++) cin>>Q[n];
    vector<int> ptn(N);
    for (int n=0; n<N; n++) ptn[n]=n+1;

    int cnt=1;
    int a=0, b=0;
    do{
        if(ptn==P) a=cnt;
        if(ptn==Q) b=cnt;
        cnt++;
    }while(next_permutation(ptn.begin(), ptn.end()));

    cout << abs(a-b) << endl;

}