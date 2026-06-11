#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    string t = s;
    int count=0;
    reverse(t.begin(),t.end());
    for(int i=0;i<s.size();i++){
        if(s.at(i)!=t.at(i)){
            count++;
        }
    }
    cout<<count/2<<endl;
}
