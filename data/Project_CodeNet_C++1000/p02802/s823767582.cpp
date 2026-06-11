#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;

    vector<int> wa(N);
    vector<int> ac(N);
    int wa_cnt = 0;
    int ac_cnt = 0;

    for(int i=0;i<M; i++){
        int p;
        string S;
        cin >> p >> S;

        if(S == "WA" && ac.at(p-1) == 0){
            wa.at(p-1)++;
        }
        if(S == "AC" && ac.at(p-1) == 0){
            wa_cnt += wa.at(p-1);
            ac_cnt += 1;
            ac.at(p-1)++;
        }

    }

    cout << ac_cnt << " " << wa_cnt << endl;
    return 0;

}