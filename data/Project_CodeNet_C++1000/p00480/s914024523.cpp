#include <iostream>
#include <vector>
#include <sstream>
#include <deque>

std::vector<std::vector<long int> > table;

void outtable(std::vector<std::vector<long int> > t){
    for(int i = 0; i < t.size(); ++i){
        for(int j = 0; j < t[i].size(); ++j){
            std::cout << t[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int calc(std::deque<int> num, int input_data_num){
    for(int i = 0; i < input_data_num - 1; ++i){
        for(int j = 0; j < 21; ++j){
            if(table[i][j] != 0){
                //std::cout << i << " " << j << std::endl;
                if(j + num.front() <= 20){
                    table[i+1][j + num.front()] += table[i][j];
                }
                if(j - num.front() >= 0){
                    table[i+1][j - num.front()] += table[i][j];
                }
                //outtable(table);
            }
        }
        num.pop_front();
    }
}

int main(){

    std::deque<int> num;
    int input_data;
    int input_data_num;
    std::string str;

    std::cin >> input_data_num;
    std::cin.ignore();

    std::getline(std::cin, str);
    std::istringstream iss(str);
    while(!iss.eof()){
        iss >> input_data;
        num.push_back(input_data);
    }

    table = std::vector<std::vector<long int> >(input_data_num, std::vector<long int>(21, 0));
    ++table[0][num.front()];

    //outtable(table);
    
    num.pop_front();

    calc(num, input_data_num);

    //outtable(table);

    std::cout << table[input_data_num-1][0] << std::endl;
    return 0;
}