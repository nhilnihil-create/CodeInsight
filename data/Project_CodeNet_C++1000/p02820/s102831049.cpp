#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
    
int main(){
    int n,k;
    int r,s,p;
    cin >> n >> k;
    cin >> r >> s >> p;
    string t;
    cin >> t;

    map <int,char> table; 
    int score = 0;

    for(int i=1; i<=n; i++){
        int amari = i % k;
        if(table.count(amari)){//k回まえが存在
            if(table.at(amari) == t[i-1]){
                table.erase(amari);
            }
            else{
                if(t[i-1] == 'r'){
                    score += p;
                    table.erase(amari);
                    table[amari] = 'r';
                }
                if(t[i-1] == 's'){
                    score += r;
                    table.erase(amari);
                    table[amari] = 's';
                }
                if(t[i-1] == 'p'){
                    score += s;
                    table.erase(amari);                    
                    table[amari] = 'p';
                }
            }

        }
        else{//kで割ったあまりが初めて
            table[amari] = t[i-1];
            if(t[i-1] == 'r'){
                score += p;
            }
            if(t[i-1] == 's'){
                score += r;
            }
            if(t[i-1] == 'p'){
                score += s;
            }
        }
    }

    cout << score << endl;
}
