/*
@author: shubham
*/

#include <bits/stdc++.h>
using namespace std;

string s;
int main() {
    cin>>s;
    string prefix="";
    string suffix="";
    int q;
    cin>>q;
    int flag=1;
    while(q--){
        int op;
        cin>>op;
        
        if(op==1){
            flag++;
        }
        else{
            int pos;
            cin>>pos;
            char ch;
            cin>>ch;
            
            if(flag%2 != 0){
                if(pos==1){
                    prefix.push_back(ch);
                }
                else{
                    suffix.push_back(ch);
                }
            }
            else{
                if(pos==1){
                    suffix.push_back(ch);
                }
                else{
                    prefix.push_back(ch);
                }
            }
        }
    }
    reverse(prefix.begin(), prefix.end());
    s = prefix + s + suffix;
    if(flag%2==0){
        reverse(s.begin(), s.end());
        cout<< s <<endl;
    }
    else{
        cout<< s <<endl;
    }
    return 0;
}
