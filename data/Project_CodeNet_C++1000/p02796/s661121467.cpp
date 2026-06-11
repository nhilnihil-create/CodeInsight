#include <bits/stdc++.h>

class index_sync_sort{
public:
    int N;
    std::vector< int > index;
    std::vector< int > data;
    std::vector< int > sync_data;
    
    index_sync_sort(int N_in){
        N = N_in;
        index.resize(N);
        data.resize(N);
        sync_data.resize(N);
        for(int i=0; i<N; i++){
            index[i] = i;
        }
    }
    
    void sort(int begin, int end){
        if(begin == end){
            return;
        }
        int tmp = begin;
        int threshold;
        while(1){
            tmp++;
            if(tmp > end){ return; }
            if(data[begin] > data[tmp]){
                threshold = data[begin];
                break;
            }else if(data[begin] < data[tmp]){
                threshold = data[tmp];
                break;
            }
        }
        int head_index = begin;
        int tail_index = end;
        while(1){
            while(data[head_index] < threshold){
                head_index++;
            }
            while(data[tail_index] >= threshold){
                tail_index--;
            }
            if(head_index > tail_index){
                break;
            }else{
                std::swap(data[head_index], data[tail_index]);
                std::swap(index[head_index], index[tail_index]);
                std::swap(sync_data[head_index], sync_data[tail_index]);
                head_index++;
                tail_index--;
            }
        }
        
        sort(begin, head_index - 1);
        sort(head_index, end);
        return;
    }
};

int main(){
    int N;
    std::cin >> N;
    index_sync_sort S(N);
    for(int i=0; i<N; i++){
        int tmp1, tmp2;
        std::cin >> tmp1 >> tmp2;
        S.sync_data[i] = tmp1 - tmp2;
        S.data[i] = tmp1 + tmp2;
    }
    
    S.sort(0, N - 1);
    
    int cnt = 0;
    int pre_right = -1e9;
    
    for(int i=0; i<N; i++){
        if(pre_right <= S.sync_data[i]){
            pre_right = S.data[i];
            cnt++;
        }
    }
    
    std::cout << cnt << std::endl;
    
    
    return 0;
}

