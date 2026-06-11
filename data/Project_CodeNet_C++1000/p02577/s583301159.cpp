#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string S;
    cin>>S;
    int length = S.length();
    // cout<<length<<endl;
    // int a = S.at(0)-'0';
    // cout<<a<<endl;
    int tmp = 0;
    for(int i=0;i<length;i++){
        int a = S.at(i) - '0';
        tmp += a;
        tmp = tmp%9;
    }
    if(tmp == 0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}