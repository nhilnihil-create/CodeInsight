#include<bits/stdc++.h>

#define Bye return 0
#define ll long long

using namespace std;

const int M = 1e5+1;

vector<int> marked(M, false);
vector<int> wrong_answers(M, 0);

void solve(){
    int n, m; cin>>n>>m;
    
    int AC = 0, WA = 0;
    for (int i=0; i<m; i++){
        int pos; string ans; cin>>pos>>ans;
        if(marked[pos]) continue;
        if(ans == "AC"){
            marked[pos] = true;
            AC++;
            WA += wrong_answers[pos];
        } else
            wrong_answers[pos]++;
    }
    cout<<AC<<" "<<WA<<endl;
}

int main(){
    solve();
    Bye;
}