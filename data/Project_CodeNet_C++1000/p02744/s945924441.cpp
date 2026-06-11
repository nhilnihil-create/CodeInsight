#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N;
vector<string> strings;
void dfs(string s,char mx){
    if(s.length()==N){
        printf("%s\n",s.c_str());
    }else{
        for(char c='a'; c<=mx; c++){
            if(c==mx){
                dfs(s+c,(char)(mx+1));
            }else{
                dfs(s+c,mx);
            }

        }
    }

}

void solve(){
    
    
    cin >> N;
    dfs("",'a');
    
}

int main(){
    solve();
}