#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)

int main(){
    int n; cin >> n;
    string s; cin >> s;

    int cnt = 0;
    int i=0, j=n-1;
    while(i<j){
        if(s[i]=='W' && s[j]=='R'){
            cnt++;
            i++;
            j--;
        }else{
            if(s[j]=='W'){
                j--;
            }
            if(s[i]=='R'){
                i++;
            }
        }
    }
    cout << cnt << endl;
}