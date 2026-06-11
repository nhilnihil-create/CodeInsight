#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    string S;
    getline(cin, S);
    while(S.length() - 1){
        stack<char> st;
        bool flag = 0;
        for(char c:S){
            if(c == '[' || c == '(')st.push(c);
            if(c == ']' || c == ')'){
                if(st.size() == 0){
                    flag = 1;
                    break;

                }
                char t = st.top();
                st.pop();
                if(!(t == '[' && c == ']' || t == '(' && c == ')')){
                    flag = 1;
                    break;
                }
            }
        }
        if(!flag && st.size() == 0)cout << "yes" << endl;
        else    cout << "no" << endl;
        getline(cin, S);
    }
}
