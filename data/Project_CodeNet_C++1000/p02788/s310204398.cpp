#include <bits/stdc++.h>

int main(){
    int N, D, A;
    std::cin >> N >> D >> A;
    std::vector< std::pair< int, long long > > XH(N);
    for(int i=0; i<N; i++){
        std::cin >> XH[i].first >> XH[i].second;
        XH[i].second = XH[i].second / A + (int)(XH[i].second % A != 0);
    }
    
    std::sort(XH.begin(), XH.end());

    long long cnt = 0;
    std::deque< int > bomb_end;
    std::deque< int > bomb_num;
    int cur_bomb_total = 0;
    for(int i=0; i<N; i++){
        while(!bomb_end.empty()){
            if(bomb_end[0] < XH[i].first){
                cur_bomb_total -= bomb_num[0];
                bomb_end.pop_front();
                bomb_num.pop_front();
            }else{
                break;
            }
        }
        if(XH[i].second <= cur_bomb_total){
            continue;
        }
        bomb_end.push_back(XH[i].first + 2 * D);
        bomb_num.push_back(XH[i].second - cur_bomb_total);
        cnt += XH[i].second - cur_bomb_total;
        cur_bomb_total = XH[i].second;

    }

    std::cout << cnt << std::endl;
    return 0;
}

