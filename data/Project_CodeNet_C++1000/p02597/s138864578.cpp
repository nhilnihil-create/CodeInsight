#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,redkosuu=0,ans=0;
    cin >> n;
    vector<char> A(n);
    for(int i=0;i<n;i++){
        char c;
        cin >> c;
        A.at(i)=c;
        if(c=='R')redkosuu++;
    }
    for(int i=0;i<redkosuu;i++){
        if(A.at(i)!='R')ans++;
    }
    cout << ans << endl;
    return 0;
}