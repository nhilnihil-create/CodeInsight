#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define INF 100000000
int main(){
    string S;
    cin>>S;
    sort(S.begin(),S.end());
    if(S[0]==S[1]&&S[1]!=S[2]&&S[2]==S[3])cout<<"Yes";
    else cout<<"No";
}
