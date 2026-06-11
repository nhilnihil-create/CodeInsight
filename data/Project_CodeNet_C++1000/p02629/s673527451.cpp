#include<bits/stdc++.h>
using namespace std;

int main(){
    long long N;
    stack<char> ans;
    cin >> N;
    while(N){
        --N;
        ans.push('a'+(N%26));
        N /= 26;
    }
    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }
    cout << endl;
    return 0;
}