#include<bits/stdc++.h>
using namespace std;
int n;
void dfs(int i, string s, char c){
    if(i == n) {
        printf("%s\n", s.c_str());
    }
    else{
        for (char j = 'a'; j <= c + 1; j++)
        {
            string t = s + j;
            dfs(i+1,t,max(c,char(j)));
        }
        
    }
}


int main(){
    cin >> n;
    dfs(1,"a",'a');
}