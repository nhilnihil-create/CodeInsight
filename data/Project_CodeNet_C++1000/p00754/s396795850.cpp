#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for(int i = m; i < (n); ++i)
#define pb push_back

int main()
{
    string str;
    
    while(getline(cin, str) && str != ".")
    {
        int t;
        stack<int> st;
        
        rep(i, str.size()) {
            switch (str[i]) {
                case '(':
                    st.push(1);
                    break;
                case '[':
                    st.push(2);
                    break;
                case ')':
                    if(st.empty()) goto no;
                    t = st.top(); st.pop();
                    if(t != 1) goto no;
                    break; 
                case ']':
                    if(st.empty()) goto no;
                    t = st.top(); st.pop();
                    if(t != 2) goto no;
                    break; 
            }
        }
        if(!st.empty()) goto no;
        cout << "yes" << endl;
        continue;
    no:;
        cout << "no" << endl;
    }
}