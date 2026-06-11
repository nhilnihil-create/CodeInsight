#include<bits/stdc++.h>

using namespace std;

int main(){
    int count[26]={0};
    set<char> letters;
    char S[4];
    cin >> S;
    //for(int i = 0; i< 26; ++i) cout<<count[i];
   // cout <<"\n";
    bool morethantwo = false;
    for(int i = 0; i<4;++i){
        letters.insert(S[i]);
        int a = ++count[(int)S[i]-'A'];
       // cout << a<<"===a\n"<<"count==="<<count['A'-S[i]]<<"\n";
        if(a>2){
            morethantwo = true;
        }
    }
   // for(int i = 0; i< 26; ++i) cout<<count[i];
    //cout <<"\n";
    if(letters.size()==2 && !morethantwo){
        cout << "Yes";
    }else cout << "No";
}