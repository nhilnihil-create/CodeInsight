#include <bits/stdc++.h>

int main(){
    int H, W, M;
    std::cin >> H >> W >> M;
    std::map< std::string, int > bomb_pos;
    //std::vector< std::vector< int > > bomb_pos(H);
    std::vector< int > H_bomb_cnt(H);
    std::vector< int > W_bomb_cnt(W);
    
    for(int i=0; i<M; i++){
        int tmp_h, tmp_w;
        std::cin >> tmp_h >> tmp_w;
        tmp_h--;
        tmp_w--;
        H_bomb_cnt[tmp_h]++;
        W_bomb_cnt[tmp_w]++;
        std::ostringstream oss;
        oss << tmp_h << "_" << tmp_w;
        std::string tmp_s = oss.str();
        //bomb_pos[tmp_h].push_back(tmp_w);
        bomb_pos[tmp_s] = 1;
    }
    
    int H_max = 0;
    std::vector< int > H_maxpos;
    int W_max = 0;
    std::vector< int > W_maxpos;
    for(int i=0; i<H; i++){
        if(H_max < H_bomb_cnt[i]){
            H_maxpos.assign(1, i);
            H_max = H_bomb_cnt[i];
        }else if(H_max == H_bomb_cnt[i]){
            H_maxpos.push_back(i);
        }
    }
    for(int i=0; i<W; i++){
        if(W_max < W_bomb_cnt[i]){
            W_maxpos.assign(1, i);
            W_max = W_bomb_cnt[i];
        }else if(W_max == W_bomb_cnt[i]){
            W_maxpos.push_back(i);
        }
    }
    
    for(int i=0; i<H_maxpos.size(); i++){
        for(int j=0; j<W_maxpos.size(); j++){
            std::ostringstream oss;
            oss << H_maxpos[i] << "_" << W_maxpos[j];
            std::string tmp_s = oss.str();
            auto itr = bomb_pos.find(tmp_s);
            if(itr == bomb_pos.end()){
                std::cout << H_max + W_max << std::endl;
                return 0;
            }
        }
    }
    
    std::cout << H_max + W_max - 1 << std::endl;
    
    
    return 0;
    
}
