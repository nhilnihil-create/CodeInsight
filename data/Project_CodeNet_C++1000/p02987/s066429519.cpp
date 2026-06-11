#include <bits/stdc++.h>
using namespace std;
int main(){
    string inp;
    cin >> inp;
    sort(inp.begin(), inp.end());
    if(inp[0]==inp[1]&&inp[2]==inp[3]&& inp[2]!=inp[1]){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}
