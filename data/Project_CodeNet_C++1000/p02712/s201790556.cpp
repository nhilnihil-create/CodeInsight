#include<bits/stdc++.h>

using namespace std;
int N;

int main(){
    cin >> N;
    long long ans[N];
    ans[0] = 0;
    for(int i= 1; i <= N; i++){
        if(i % 5 == 0 || i % 3 == 0){
            ans[i] = 0;
            }
        else{ans[0] += i;}
    }
    cout << ans[0] << endl;
}