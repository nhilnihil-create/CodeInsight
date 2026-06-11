#include <bits/stdc++.h>

#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
// #define int long long
#define endl '\n'

using namespace std;

const int N = 2e5 + 77;

string s;

int32_t main()
{
    cin >> s;
    int n = s.size();

    vector<int> A(n,1);

    for(int i = 0; i < n ; ++i){
        if(s[i]=='R' && s[i+1]=='R'){
            A[i+2] += A[i];
            A[i] = 0;
        }
    }

    for(int i = n-1 ; i >= 0 ; --i){
        if(s[i]=='L' && s[i-1]=='L'){
            A[i-2] += A[i];
            A[i] = 0;
        }
    }

    for(int i = 0 ; i < n ; ++i){
        if(i==0) cout << A[i] ;
        else cout << ' ' << A[i];
    }
    cout << endl;
    return 0;
}