#include <iostream>
#include<map>
#define REPD(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) REPD(i, 0, n)
 
using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    string S;
    cin >> S;
    bool flag = true;
    REP(i,S.length()-1){
        if (S[i] == S[i + 1])
        {
            flag = false;break;
        }
    }
    if(flag) fin("Good");
    else fin("Bad");
    return 0;
}