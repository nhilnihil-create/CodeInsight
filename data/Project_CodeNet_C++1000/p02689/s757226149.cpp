#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector< vector<char> > vvc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef long long ll;

int main(){
    int N,M;
    cin >> N >> M;
    vi h(N+1);
    for(int i=1;i<=N;i++){
        cin >> h[i];
    }
    vvi adjlist(N+1);
    for(int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    int cnt=0;
    for(int i=1;i<=N;i++){
        bool flag=true;
        for(int adj : adjlist[i]){
            //cout << adj ;
            if(h[i]<=h[adj]) flag=false;
        }
        //cout << endl;
        if(flag) cnt++;
    }
    cout << cnt << endl;
    return 0;

}