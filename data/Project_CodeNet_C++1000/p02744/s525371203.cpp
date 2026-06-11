#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    queue<pair<string,int>> q;
    q.push(make_pair("a",1));
    int len=1;
    while (1)
    {
        if(q.size()==0)break;
        len=q.front().first.size();
        if(len==n){
            cout<<q.front().first<<endl;
            q.pop();
        }else{
            int kinds=q.front().second;
            string s=q.front().first;
            char c='a';
            for (int i = 0; i < kinds;i++){
                q.push(make_pair(s+c,kinds));
                c=(char)((int)c+1);
            }
            q.push(make_pair(s+c,kinds+1));
            q.pop();
        }
    }
    
}