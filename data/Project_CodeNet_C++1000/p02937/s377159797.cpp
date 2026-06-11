#include <bits/stdc++.h>

std::vector< std::vector< int > > exist_No(26);

int binary_search(int word_No, int key) {
    int left = -1;
    int right = (int)exist_No[word_No].size();
    
    while(right - left > 1){
        int mid = left + (right - left) / 2;
        
        if(exist_No[word_No][mid] > key){
            right = mid;
        }else{
            left = mid;
        }
    }
    
    return right;
}

int main(){
    std::string S, T;
    std::cin >> S >> T;
    
    for(int i=0; i<S.size(); i++){
        exist_No[S[i] - 'a'].push_back(i);
    }
    
    long long cnt = 0;
    int cur_word = -1;
    for(int i=0; i<T.size(); i++){
        if(exist_No[T[i] - 'a'].size() == 0){
            std::cout << -1 << std::endl;
            return 0;
        }
        if(exist_No[T[i] - 'a'][exist_No[T[i] - 'a'].size() - 1] <= cur_word){
            cnt += S.size();
            cur_word = -1;
        }
        
        int cur_index = binary_search(T[i] - 'a', cur_word);
        cur_word = exist_No[T[i] - 'a'][cur_index];
    }
    cnt += cur_word + 1;
    
    
    std::cout << cnt << std::endl;
    
    return 0;
}

