#include<bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

const int INF = 1e9;

int main(){
    int N;
    cin >> N;

    // (pos, length)
    // (first, last)
    vector<pii> P(N);

    for(int i=0; i<N; i++){
        int pos, length;
        cin >> pos >> length;

        P.at(i).first = pos - length;
        P.at(i).second = pos + length;
    }

    sort(P.begin(), P.end(), [](pii p1, pii p2)->bool{return p1.second < p2.second;});

    // for(pii p : P)cout << "(" << p.first << "," << p.second << ")" << " ";
    // cout << endl;

    int now = -INF;
    int count = 0;
    for(int i=0; i<N; i++){
        pii p = P.at(i);
        if(now <= p.first){
            now = p.second;
            count++;
        }
    }

    cout << count << endl;
}