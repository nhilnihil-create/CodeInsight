#include <bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin >> s;
    int n=s.size();
    string s_1,s_2;
    s_1=s[0];
    int cnt=1;
    for(int i=1; i<n; i++){
        s_2=s[i];
        if(s_1==s_2&&i==n-1)break;
        if(s_1!=s_2)s_1=s_2;
        else{
            i++;
            s_2+=s[i];
            s_1=s_2;
        }
        cnt++;
    }
    cout << cnt << endl;
}