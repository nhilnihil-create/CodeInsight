#include <bits/stdc++.h>
using namespace std;

#define print cout <<
#define printl(s) cout << s << endl;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N,K;
    cin >> N >> K;
    set<int> sunukeS;
    rep(i,N){
      sunukeS.insert(i+1);
    }
    rep(i,K){
      int tgt;
      cin >> tgt;
      rep(g,tgt){
        int sunu;
        cin >> sunu;
        if(sunukeS.count(sunu)){
          sunukeS.erase(sunu);
        }
      }
    }
    printl(sunukeS.size());
}
