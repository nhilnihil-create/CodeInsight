#include <iostream>
#include <stack>
#include <string>
using namespace std;
typedef unsigned long long ULL;
int main()
{
    stack<int> st;
    string s;
    int tmp=0,tmp2=0;
    while(cin >> s)
    {
        if(s == "+") 
        {
            tmp = st.top();
            st.pop();
            tmp2 = st.top();
            st.pop();
            st.push(tmp2 + tmp);
        }
        else if(s == "-")
        {
            tmp = st.top();
            st.pop();
            tmp2 = st.top();
            st.pop();
            st.push(tmp2 - tmp);
        }
        else if(s == "*")
        {
            tmp = st.top();
            st.pop();
            tmp2 = st.top();
            st.pop();
            st.push(tmp2 * tmp);
        }
        else
        {
            st.push(stoi(s));
        }
    }
        cout << st.top() << endl;
    return 0;   
}