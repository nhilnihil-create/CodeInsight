#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    //freopen("Areas.txt", "r", stdin);
    stack<int> s1;
    stack<pair<int, int>> s2;
    stack<int> res;
    char c;
    int cnt = 0;
    int floodcnt = 0;
    int area = 0;
    int leftIndex;
    int tempArea;
    int mergeArea;
    pair<int, int> tempPair;
    while(scanf("%c", &c) != EOF){
        cnt++;
        if(c == '\\'){
            s1.push(cnt);
        }
        if(c == '/'){
            if(!s1.empty()){
                leftIndex = s1.top();
                s1.pop();
                tempArea = cnt-leftIndex;
                area += tempArea;
                while(!s2.empty()){
                    tempPair = s2.top();
                    if(tempPair.first > leftIndex){
                        s2.pop();
                        mergeArea = tempPair.second;
                        tempArea += mergeArea;
                    }
                    else{
                        break;
                    }
                }
                s2.push(make_pair(leftIndex, tempArea));
            }
        }
    }
    printf("%d\n", area);
    if(s2.size() == 0){
        printf("%d\n", s2.size());
    }
    else{
        printf("%d ", s2.size());
        while(!s2.empty()){
            res.push(s2.top().second);
            s2.pop();
        }
        while(res.size() > 1){
            printf("%d ", res.top());
            res.pop();
        }
        if(res.size() == 1){
            printf("%d\n", res.top());
            res.pop();
        }
    }
    return 0;
}

