#include <iostream>
#include <vector>
#include <algorithm>

void showVector(std::vector<int> readVec){
    int size = readVec.size();
    for(int i = 0; i < size; ++i){
        std::cout << readVec.at(i);
        if(size - 1 != i){
            std::cout << " ";
        }else{
            std::cout << std::endl;
        }
    }
}

int selectionSort(std::vector<int> &readVec){
    int n = readVec.size();
    int index, count = 0;
    for(int i = 0; i < n; ++i){
        int index = i;
        for(int j = i; j < n; ++j){
            if(readVec.at(j) < readVec.at(index)){
                index = j;
            }
        }

        if(index != i){
            readVec.at(i) += readVec.at(index);
            readVec.at(index) = readVec.at(i) - readVec.at(index);
            readVec.at(i) = readVec.at(i) - readVec.at(index);
            ++count;
        }
    }
    
    return count;
}


int main(){
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a.at(i);
    }

    int count = selectionSort(a);
    showVector(a);
    std::cout << count << std::endl;

    return 0;
}

