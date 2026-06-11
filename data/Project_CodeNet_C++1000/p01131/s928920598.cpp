#include <iostream>

std::string table[10] = {"",
                         ".,!? ",
                         "abc",
                         "def",
                         "ghi",
                         "jkl",
                         "mno",
                         "pqrs",
                         "tuv",
                         "wxyz"};

int main(){
    int N;
    std::cin >> N;

    for(;N--;){
        std::string S;
        std::cin >> S;

        int key = -1, index = -1;
        std::string T = "";
        for(char c : S){
            if(c == '0'){
                if(~key){
                    T += table[key][index];
                    key = -1;
                    index = -1;
                }
            }else{
                if(!~key){
                    key = c - '0';
                    index = 0;
                }else{
                    index = (index+1) % table[key].size();
                }
            }
        }

        std::cout << T << std::endl;
    }
}