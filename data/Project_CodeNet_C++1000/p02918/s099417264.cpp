#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int tmp = 0;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1])tmp++;
    }
    cout<<min(tmp+2*k,n-1)<<endl;
}