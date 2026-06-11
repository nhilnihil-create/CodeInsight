#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    int q;
    cin >> s;
    cin >> q;
    deque<char> ds;
    for(int i=0; i<s.size(); i++){
        ds.push_back(s.at(i));
    }
    int rev=0;
    for(int i=0; i<q; i++){
        int t;
        cin >> t;
        if(t==1){
            rev = 1 - rev;
        }
        else{
            int f;
            char c;
            cin >> f;
            f--;
            cin >> c;
            if(f == rev){
                ds.push_front(c);
            }
            else{
                ds.push_back(c);
            }
        }
    }
    if(rev){
        while(!ds.empty()){
            cout << ds.back();
            ds.pop_back();
        }
    }
    else{
        while(!ds.empty()){
            cout << ds.front();
            ds.pop_front();
        }
    }
    cout << endl;
}
