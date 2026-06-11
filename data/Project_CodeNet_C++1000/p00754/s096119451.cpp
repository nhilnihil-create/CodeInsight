#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define all(c) (c).begin(), (c).end()

bool solve(string& s){
    s.erase(remove_if(all(s), [](char c){return string("()[]").find(c) == string::npos;}), s.end());
    vector<char> st;
    for(auto c: s){
        if(c == '(' || c == '[')st.push_back(c);
        else if(st.empty() || st.back() != (c == ')'? '(': '['))return false;
        else st.pop_back();
    }
    return st.empty();
}

vector<string> split(const string& in, char delim){
    istringstream stream(in);
    string field;
    vector<string> res;
    while(getline(stream, field, delim) && !field.empty())res.push_back(field);
    return res;
}

int main(){
    string buf = "";
    for(string line; getline(cin, line); line.erase(remove(all(line), '\n'), line.end()), buf += line);
    for(auto s: split(buf, '.'))cout << (solve(s)? "yes\n": "no\n");
    return 0;
}