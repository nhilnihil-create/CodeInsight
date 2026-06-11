#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#define mod 1000000007
typedef long long ll;
using namespace std;

int N;

// next := sの中に登場していないアルファベットのうち最小のもの
void dfs(string s, char next){
    if(s.size() == N){
        cout << s << "\n";
        return;
    }else{
        for(char c='a';c<=next;c++){
            if(c != next){
                dfs((string)(s+c),next);
            }else{
                dfs((string)(s+c), (char)(next+1));
            }
        }
    }
}

int main(){
    cin >> N;
    dfs("",'a');
    return 0;
}