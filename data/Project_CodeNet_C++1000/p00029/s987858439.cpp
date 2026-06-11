#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main(void)
{
    priority_queue <string> word;
    char str[35];
    int top_num = 0, now_num = 0, max_len = 0;
    string s, max, top, prev;
    
    while (scanf("%s", str) == 1){
        word.push(str);
        s = str;
		if(max_len < s.size()){
            max_len = (int)s.size();
            max = s;
        }

    }
    
    prev = word.top();
    while (!word.empty()){
        if (prev == word.top()){
            now_num++;
            if (top_num < now_num){ 
                top_num = now_num;
                top = word.top();
            }
        }
        else now_num = 0;
        prev = word.top();
        word.pop();
    }
    
    printf("%s %s\n", top.c_str(), max.c_str());
    
    return 0;
}