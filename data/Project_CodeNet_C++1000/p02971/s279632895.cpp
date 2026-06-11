#include<vector>
#include<iostream>
#include <algorithm>


std::vector<int> return_sort(std::vector<int> vec){

    std::sort(vec.begin(), vec.end()); //昇順 
    return vec;
}

int main(){

    int N;
    std::vector<int> nums, nums_sorted;
    std::cin >> N;
    for(int num; std::cin >> num;){
        nums.push_back(num);
    }
    nums_sorted = return_sort(nums);
    int x = 0;
    for(int i = 0; i < N; ++i){
            x = nums.at(i);
            if(nums_sorted.at(N-1) - x == 0){
                std::cout << nums_sorted.at(N-2) << std::endl;
            }else{
                std::cout << nums_sorted.at(N-1)<<std::endl;
            }
    }
}