#include <iostream>
#include <queue>
#include <string>
using namespace std;


int main()
{
    string s;
    int k;
    priority_queue<int> que;
    while(cin >> s, s != "end"){
        if(s == "insert"){
            cin >> k;
            que.push(k);
        } else {
            cout << que.top() << endl;
            que.pop();
        }
    }
}