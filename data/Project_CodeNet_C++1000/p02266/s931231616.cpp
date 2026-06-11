#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 20000+5;
stack<int> pos;
stack<int> ss;
stack<int> leftmost;
std::vector<int> v;
char c[MAX];
int sums = 0;   //总面积
int cs = 0;     //当前面积
int main(int argc, char const *argv[])
{
    cin >> c;
    int len = strlen(c);
    for(int i = 0;i < len;i++){
        if(c[i] == '\\')    pos.push(i);
        if(c[i] == '/' && pos.size() > 0){
            int cpos = pos.top();
            pos.pop();
            cs = i-cpos;
            sums += cs;
            //保证当前积水坑的最左边的'\'的位置 > pos中'\'的位置(已经回退到的位置)
            while(ss.size() > 0 && leftmost.top() > cpos){
                cs += ss.top();
                leftmost.pop();
                ss.pop();
            }
            ss.push(cs);
            leftmost.push(cpos);
        }
    }
    cout << sums << endl;

    while(!ss.empty()){
        v.push_back(ss.top());
        ss.pop();
    }
    cout << v.size();
    reverse(v.begin(),v.end());
    for(std::vector<int>::iterator it = v.begin(); it != v.end();it++)
        cout <<" "<< *it;
    cout << endl;
    return 0;
}
