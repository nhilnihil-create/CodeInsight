#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string, int> memo;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(memo.count(s)){
            memo[s]++;
            //memo.at(s)++;
        }else{
            memo[s] = 1;
        }
    }

    int maxnum = -1;
    for(auto p: memo){
        if(p.second > maxnum){
            maxnum = p.second;
        }
    }

    for(auto p: memo){
        if(p.second == maxnum){
            cout << p.first << endl;
        }
    }
    return 0;
}