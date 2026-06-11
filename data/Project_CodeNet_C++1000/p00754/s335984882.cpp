#include <bits/stdc++.h>
using namespace std;
#define N_PRIME 1000000007
#define ll int64_t

void solve(){
    string s;
    getline(cin,s);
    if( s==".")exit(0);
    stack<int> t;
    
    
    for(int i = 0 ; i < s.size() ; i++ ){
        if( s[i] == '(' ){
            t.push(0);
        }else if( s[i] == '[' ){
            t.push(1);
        }else if( s[i] == ')' ){
            if( t.size() == 0 || t.top() != 0 ){
                cout << "no" << endl;
                return ;
            }else{
                t.pop();
            }
        }else if( s[i] == ']' ){
            if( t.size() == 0 || t.top() != 1 ){
                cout << "no" << endl;
                return ;
            }else{
                t.pop();
            }
        }
    }
    
    if( t.size() > 0 ){
        cout << "no" << endl;
    }else{
        cout << "yes"<<endl;
    }
    return ;
}
int main(void){
    while(true)solve();
    return 0;
}