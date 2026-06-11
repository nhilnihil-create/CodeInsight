#include<bits/stdc++.h>
using namespace std;
int n;
void dfs(int i, string s, char c){
    if(i == n) {
        cout << s << endl;
    }
    else{
        for (char j = 'a'; j <= c + 1; j++)
        {
            string t = s + j;
            if(j == c+1) dfs(i+1,t,c+1);
            else dfs(i+1,t,c);
        }
        
    }
}


int main(){
    cin >> n;
    dfs(1,"a",'a');
}