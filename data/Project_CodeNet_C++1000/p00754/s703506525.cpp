#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,k,n) for(int i=k;i<(int)(n);i++)

#define vi vector<int>
#define pb push_back

typedef long long ll;


int main(){
//    ifstream in("bin.txt");
//    cin.rdbuf(in.rdbuf());
    string s;
    while(getline(cin,s),s[0]!='.'){
        bool flag = true;
        stack<char> st;
        rep(i,s.size()){
            switch(s[i]){
                case '(':
                    st.push('(');
                    break;
                case ')':
                    if(st.empty() || st.top()!='('){
                        flag = false;
                        i = s.size();
                    }else{
                        st.pop();
                    }
                    break;
                case '[':
                    st.push('[');
                    break;
                case ']':
                    if(st.empty() || st.top()!='['){
                        flag = false;
                        i = s.size();
                    }else{
                        st.pop();
                    }
                    break;
            }
        }
        if(st.empty() && flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}
