#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    queue<pair<string,char> > que;
    priority_queue<string>answer;
    vector<string>reversed_answer;


    que.push(make_pair("a",'a'));
    if(n == 1){
        cout << "a" << endl;
        return 0;
    }

    while(!que.empty()){
        pair<string,char> temp = que.front();
        que.pop();
        for(int i = 0;i < temp.second-'a'+2;i++){
            string new_string;
            char new_char=temp.second;

            new_string = temp.first+(char)('a'+i);
            if('a'+i > temp.second)new_char = 'a'+i;
            if(new_string.length() == n){
                answer.push(new_string);
                continue;
            }
            que.push(make_pair(new_string,new_char));
        }
    }
    while(!answer.empty()){
        reversed_answer.push_back(answer.top());
        answer.pop();
    }
    reverse(ALL(reversed_answer));

    REP(i,reversed_answer.size()){
        cout << reversed_answer[i] << endl;
    }
    return 0;
}