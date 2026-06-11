#include <iostream>
#include<algorithm>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define rng(a) a.begin(),a.end()
typedef long long ll;

using namespace std;



int main() {
    string S;
    cin>>S;
    sort(rng(S));
    if(S[0]==S[1]&&S[1]!=S[2]&& S[2]==S[3])puts("Yes");
    else(puts("No"));

    return 0;
}