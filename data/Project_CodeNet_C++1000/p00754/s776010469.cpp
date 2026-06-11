#include<iostream>
#include<string>
#include<algorithm>
#include<list>
#include<stack>
#include<map>
#include<queue>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(n) rep(i,n)

int l;

int main()
{
    while(1)
    {
        string s;
        getline(cin,s);
        if(s == ".")break;

        l = s.size();
        stack<char> bra;
        
        bool ans = true;
        REP(l)
        {

            if(s[i] == '('){ bra.push('(');continue; }
            if(s[i] == '['){ bra.push('[');continue; }

            if(s[i] == ')')
            {
                if(bra.empty() || bra.top() != '('){ans = false; break;}
                bra.pop();
            }
            if(s[i] == ']')
            {
                if(bra.empty() || bra.top() != '['){ans = false; break;}
                bra.pop();
            }
        }
        if(!bra.empty()) ans = false;

        if(ans) cout<< "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}