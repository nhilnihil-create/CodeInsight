#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<bool> AC(N+1, false);
    vector<int> WA(N+1,0);

    int ACnum = 0, WAnum = 0;
    for(int i = 0; i < M; i++){
        int p;
        string S;
        cin >> p >> S;
        if(AC.at(p) == true) continue;
        if(S == "AC"){
            AC.at(p) = true;
            ACnum++;
            WAnum += WA.at(p);
        }else{
            WA.at(p)++;
        }
    }
    cout << ACnum << " " << WAnum << endl;
}
