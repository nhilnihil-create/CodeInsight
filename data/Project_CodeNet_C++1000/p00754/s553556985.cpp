#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define TEST 0
#if TEST
FILE* in = freopen("./Q.txt", "r", stdin);
FILE* out = freopen("./A.txt", "w", stdout);
#endif


char s[3] = "([";
char e[3] = ")]";

int main(int argc, const char * argv[]) {
    while(1){
        string line; getline(cin, line);
        if(line == ".") break;
        //cin.ignore();
        
        bool ok = true;
        stack<char> brackets;
        for(int i = 0; i < line.size(); i++){
            for(int j = 0; j < 2; j++){
                if (line[i] == s[j]) {
                    brackets.push(line[i]);
                } else if (line[i] == e[j]){
                    if(brackets.empty()){
                        ok = false;
                    } else {
                        ok = (brackets.top() == s[j]);
                        brackets.pop();
                    }
                }
            }
            if(!ok) break;
        }
        ok &= brackets.empty();
        cout << (ok ? "yes" : "no") << endl;
    }
#if TEST
    fclose(in);
    fclose(out);
#endif
}