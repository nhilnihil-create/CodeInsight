#include<bits/stdc++.h>
using namespace std;

int main(){
    int k; cin>>k;
    string s; cin >> s;
    int n=s.size();
    if(n>k){
        s = s.substr(0,k)+"...";
    }
    cout << s << endl;
}