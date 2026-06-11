#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N;
    string S;
    cin >> N >> S;
    char prev=' ';
    string res="";
    for(int i=0;i<N;i++){
        if(S[i]!=prev)res+=S[i];
        prev=S[i];
    }
    cout<<res.size()<<endl;
    return 0;
}