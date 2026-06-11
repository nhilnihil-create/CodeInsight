#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;2*i<s.size()-1;i++){
        if(s[i]!=s[s.size()-1-i])cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}