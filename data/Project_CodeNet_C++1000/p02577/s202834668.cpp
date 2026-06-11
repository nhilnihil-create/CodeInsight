#include <bits/stdc++.h>
#include<string>
using namespace std;
int main() {
    string N;
    cin>>N;
    int slength = N.length();
    int sum = 0;
    for(int i = 0; i < slength; i++){
        sum = sum + N[i] -'0';//'0'はマジックナンバー。内部表現数値からchar '0'(48)を引くとchar'N'は数字になるという寸法。
    }
    // cout << slength <<endl;
    if(sum%9==0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}