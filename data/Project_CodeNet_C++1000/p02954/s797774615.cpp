#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    vector<int> num(s.size(), 1);
    for(int i=0; i<s.size()-2; i++){
        if(s[i] == 'R' && s[i+1] == 'R'){
            num[i+2] += num[i];
            num[i] = 0;
        }
    }
    for(int i=s.size()-1; i>1; i--){
        if(s[i] == 'L' && s[i-1] == 'L'){
            num[i-2] += num[i];
            num[i] = 0;
        }
    }

    for(int i=0; i<s.size(); i++){
        cout<<num[i];
        if(i < s.size()-1){
            cout<<" ";
        }
    }
    cout<<endl;

    return 0;
}