#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N+1);
    for ( int i = 1; i < N+1; ++i){
        cin >> a.at(i);
    }
    
    vector<int> ans(N+1);
    for ( int i = N; i >= 1; --i){
        int sum = 0;
        int cnt = 2;
        while ( cnt * i <= N ){
            sum += ans.at(cnt*i);
            cnt += 1;
        }
        ans.at(i) = ( sum + a.at(i) )% 2;
    }
    
    int M = 0;
    vector<int> b;
    for ( int i = 1; i <= N; ++i){
        if ( ans.at(i) == 1 ){
            b.push_back(i);
            M += 1;
        }
    }
    
    cout << M << endl;
    for ( int i = 0; i < b.size(); ++i){
        cout << b.at(i) << " ";
    }
    cout << endl;
    
    return 0;
}
