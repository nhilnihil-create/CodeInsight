#include <math.h>
#include <ctype.h>
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(i, n) for(int i = 0; i < n; i++)
struct omt{omt(){ios::sync_with_stdio(false);cin.tie(0);}}star;

int main(){
    int n;
    cin >> n;

    list<int> A;
    string s;
    int tmp;
    REP(i, n){
        cin >> s;
        if(s == "insert"){
            cin >> tmp;
            A.push_front(tmp);
        }else if(s == "delete"){
            cin >> tmp;
            for(auto itr = A.begin(); itr != A.end(); ++itr){
                if(*itr == tmp){
                    A.erase(itr);
                    break;
                }
            }
        }else if(s == "deleteFirst") A.pop_front();
        else if(s == "deleteLast") A.pop_back();
    }

    vector<int> B;
    for(auto itr = A.begin(); itr != A.end(); ++itr){
        B.push_back(*itr);
    }
    REP(i, B.size()){
        if(i != B.size() - 1) cout << B[i] << " ";
        else cout << B[i] << endl;
    }


    return 0;
}
