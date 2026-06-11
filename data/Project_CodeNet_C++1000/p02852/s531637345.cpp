#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N,M;
    string S;
    cin >> N >>M>> S;
    N++;
    reverse(S.begin(),S.end());
    vector<int> ans;
    int i=0;
    while(i<N-1){
        int next = min(i+M,N-1);
        // cerr <<"next="<< next <<"S[next]=" << S[next] <<  endl;
        while(S[next] != '0'){
            next--;
        }
        if(next==i){
            cout << -1 << endl;
            return 0;
        }
        // cerr <<"next - i=" << next-i <<endl;;
        ans.push_back(next-i);
        i= next;
    }
    reverse(ans.begin(),ans.end());
    for(int a:ans){
        cout << a<<" ";
    }
    cout <<endl;
    return 0;
}