#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007



int main() {
    int N;
    cin >> N;

    vector<int> P(N);
    vector<int> Q(N);

    for(int i = 0; i < N; i++) cin >> P.at(i);
    for(int i = 0; i < N; i++) cin >> Q.at(i);

    vector<int> kaijou(N+1, 1);
    for(int i = 1; i < N+1; i++) kaijou.at(i) = kaijou.at(i-1) * i;

    vector<int> temp(N+1);
    for(int i = 0; i < N+1; i++) temp.at(i) = i;

    int num, cnt = 0, cnt_2 = 0;

    for(int i = 0; i < N-2; i++){
        for(int j = 1; j <= N-i; j++){
            if(P.at(i) == temp.at(j)){
                num = j;
                temp.at(j) = 1000;
                break;
            }
        }

        cnt += (num-1) * kaijou.at(N-1-i) + 1;

        sort(temp.begin(), temp.end());
    }
    if(P.at(N-2) > P.at(N-1)) cnt++;

    for(int i = 0; i < N+1; i++) temp.at(i) = i;

    for(int i = 0; i < N-2; i++){
        for(int j = 1; j <= N-i; j++){
            if(Q.at(i) == temp.at(j)){
                num = j;
                temp.at(j) = 1000;
                break;
            }
        }

        cnt_2 += (num-1) * kaijou.at(N-1-i) + 1;

        sort(temp.begin(), temp.end());
    }
    if(Q.at(N-2) > Q.at(N-1)) cnt_2++;

    cout << max(cnt, cnt_2) - min(cnt, cnt_2) << endl;
}
