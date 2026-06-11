#include <bits/stdc++.h>
#define pb push_back
#define Int int64_t
using namespace std;

Int N,K;

int main()
{
    cin>>K;
    string S;cin>>S;
    for(int i=0;i<S.length();++i){
        cout<<char(((S[i]-'A')+K)%26+'A');
    }
}