#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int K; cin >> K;
    deque<string> dq;
    int count = 0;
    for(int i=1; i <= 9; i++){
        dq.emplace_back(to_string(i));
    }

    string naw;
    while(count < K){
        naw = dq.front();
        dq.pop_front();
        count++;
        int nawlast = naw.length() - 1;
        int nawlast_r = naw[nawlast] - '0' + 1;
        int nawlast_l = naw[nawlast] - '0' - 1;

        if( nawlast_l >= 0){
            dq.emplace_back( (naw + to_string(nawlast_l)) );
        }
        dq.emplace_back( (naw + naw[nawlast] ));
        if( nawlast_r < 10){
            dq.emplace_back( (naw + to_string(nawlast_r)) );
        }

    }

    cout << naw << endl;
}