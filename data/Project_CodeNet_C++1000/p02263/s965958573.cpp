#include<iostream>
#include<sstream>
#include<stack>
#include<string>
 
using namespace std;
 
stack<string> dfs;
 
int main()
{
    string c;
    while (cin >> c) {
        if (c != "+"&&c != "-"&&c != "*")
            dfs.push(c);
        else {
            int num[2], r;
            for (int i = 0; i < 2; ++i) {
                stringstream sstr;
                sstr << dfs.top(); dfs.pop();
                sstr >> num[i];
            }
            if (c == "+")r = num[0] + num[1];
            else if(c == "-")r = num[1] - num[0];
            else r = num[0] * num[1];
            dfs.push(to_string(r));
        }
    }
    cout << stoi(dfs.top()) << endl;
}