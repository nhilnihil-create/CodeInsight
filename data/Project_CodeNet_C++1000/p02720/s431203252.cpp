#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <queue>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main(){
    queue<string> q;
    vector<string> l = {"1","2","3","4","5","6","7","8","9"};
    for(auto t : l) q.push(t);
    int n;
    cin >> n;
    int count=1;
    bool flag = true;
    string s="0";
    while(true){
        s= q.front();
        int last = s.size()-1;
        if(count==n) break;
        q.pop();
        count++;

        if(flag){
            if(s[last] == '9'){
                s.push_back(s[last]-1);
                q.push(s);
                s.pop_back();
                s.push_back(s[last]);
                q.push(s);
            }else if(s[last] == '0'){
                s.push_back(s[last]);
                q.push(s);
                s.pop_back();
                s.push_back(s[last]+1);
                q.push(s);

                if(s.size() >= 11) flag = false;

            }else{
                for(int i = -1;i<2;i++){
                    s.push_back(s[last]+i);
                    q.push(s);
                    s.pop_back();
                }
            }
        }
    }
    char ch = '9' + n;
    cout << s << endl;
}


