#include <iostream>
#include <vector>
#include <cstdio>
#include <stack>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

#define dump(x)  cerr << #x << " = " << (x) << endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back


int main(){
    string s;
    while(getline(cin,s)){
        stack<char> data;
        while(data.size())data.pop();
        if(s==".")break;

        rep(i,s.size()){
            if(s[i]=='[')data.push('[');
            if(s[i]=='(')data.push('(');
            if(s[i]==']'){
                if(data.size() && data.top()=='[')data.pop();
                else{
                    cout<<"no"<<endl;
                    break;
                }
            }
            if(s[i]==')'){
                if(data.size() && data.top()=='(')data.pop();
                else{
                    cout<<"no"<<endl;
                    break;
                }
            }
            if(i==s.size()-1)
                if(data.empty()) cout<<"yes"<<endl;
                else cout<<"no"<<endl;
        }
    }
    return 0;
}