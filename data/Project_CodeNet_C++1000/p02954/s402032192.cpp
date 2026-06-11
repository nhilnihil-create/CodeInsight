#include<iostream>
#include<vector>

int main(void){
    std::string s;
    std::cin >> s;
    int size = s.size();
    char mark = 'R';
    std::vector<int> rpos, lpos;
    std::vector<int> a(size);
    rpos.push_back(0);
    for(int i = 0; i < size; i++){
        if(s[i] != mark){
            if(mark == 'R'){
                lpos.push_back(i);
                mark = 'L';
            }else{
                rpos.push_back(i);
                mark = 'R';
            }
        }
    }
    int rpos_size = rpos.size();
    int tot, tmp;
    for(int i = 0; i < rpos_size; i++){
        if(i == rpos_size - 1) {
            tot = size - rpos[i];
            tmp = (size - 1 - lpos[i]) / 2;
        }else{
            tot = rpos[i+1] - rpos[i];
            tmp = (rpos[i+1] - 1 - lpos[i]) / 2;
        }
        tmp += (lpos[i] - rpos[i]) / 2;
        tmp++;
        a[lpos[i]] = tmp;
        a[lpos[i] - 1] = tot - tmp;
    }

    for(int i = 0; i < size; i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}