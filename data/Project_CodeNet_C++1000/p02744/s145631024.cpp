#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
using G=vector<vector<int>>;
int n;
vector<int> str(11);
void dfs(int saidai,int phase){
    if(phase==n) {
        rp(i,n){
            char ch='a'+str[i];
            cout << ch;
        }
        cout << endl;
        return;
    }
    rp(i,saidai+2){
        str[phase]=i;
        if(i<=saidai){
            dfs(saidai,phase+1);
        }
        else{
            dfs(i,phase+1);
        }
    }
}
int main(){
    cin >> n;
    str[0]=0;
    dfs(0,1);
    return 0;
}