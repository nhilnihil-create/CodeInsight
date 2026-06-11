#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin >> s;
    int n = s.size();
    string s_i = "";
    int counter = 0;
    int ans = 0;
    while(counter<n){
        if(counter == n-1 && s_i==s.substr(counter,1)) break;
        if(s_i==s.substr(counter,1)){
            s_i=s.substr(counter,2);
            ans ++;
            counter +=2;
        }
        else{
            s_i=s.substr(counter,1);
            ans ++;
            counter ++;
        }
    }
    cout << ans << endl;
}