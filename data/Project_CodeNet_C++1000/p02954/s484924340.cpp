#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int r=0,l=0,t[100007]={},n=s.size();
    for(int i=0;i<n-1;i++){
        if(s[i]=='R') r++;
        if(s[i]=='L') l++;
        if(l==0&&s[i+1]=='L'){
            t[i+1] += r/2;
            t[i] += r-r/2;
            r=0;
        }
        if(r==0&&(s[i+1]=='R'||i==n-2)){
            int c = l+(i==n-2);
            t[i-l] += c/2;
            t[i-l+1] += c-c/2;
            l=0;
        }
    }
    for(int i=0;i<n;i++) cout << t[i] << ' ';
    cout << endl;
}