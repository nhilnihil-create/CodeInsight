#include <iostream>
#include<map>
#define REPD(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) REPD(i, 0, n)

using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    string S;
    bool flag = true;
    cin >> S;
    map<char,int> m;
    REP(i,S.length()){
        m[S[i]]++;
    }
    REP(i,S.length()){
        if(m[S[i]] == 2){
            continue;
        }else{
            flag = false;break;
        }
    }
    if(flag)fin("Yes");
    else fin("No");
    return 0;
}