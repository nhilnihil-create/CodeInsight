#include <bits/stdc++.h>
     
using namespace std;
typedef long long ll;
const int tmax=3010;
const int nmax=3010; 
long DP[nmax][tmax];
int a[nmax],b[nmax];
char word[tmax];

int N;

void DFS(ll level){
    char climit =(char)'a';
    for (ll i=0; i< level; i++){
        climit = climit > (word[i]+1) ? climit : (word[i]+1);
    }
    for(char j='a'; j<= climit; j++){
        word[level] = j;
        if(level + 1 == N){
            word[level+1]='\0';
            cout << word << endl;
        } else
        {
            DFS(level + 1);
        }
    }
}


void solve(void){
    // cout << N << endl;  
    DFS(0);   
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    solve();
    
}

