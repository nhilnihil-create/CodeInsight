#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define len(v) (int)(v).size()

using namespace std;

int main()
{
    while(1){
        string s;
        getline(cin,s);
        if(s == "."){
            break;
        }
        int a = 0, b = 0;
        stack<int> st;
        bool ok = true;
        rep(i,len(s)){
            if(s[i] == '('){
                a++;
                st.push(0);
            }else if(s[i] == ')'){
                a--;
                if(a < 0 || st.top() == 1){
                    ok = false;
                    break;
                }else{
                    st.pop();
                }
            }else if(s[i] == '['){
                b++;
                st.push(1);
            }else if(s[i] == ']'){
                b--;
                if(b < 0 || st.top() == 0){
                    ok = false;
                    break;
                }else{
                    st.pop();
                }
            }
        }
        if(ok && a == 0 && b == 0){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
    }
}

