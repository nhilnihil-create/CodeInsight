#include<iostream>
#include<vector>
#include<math.h>

class ShellSort{
private:
    std::vector<int> dataSet;
    std::vector<int> vecG;
    int m;
    int changeCount;
public:
    ShellSort(std::vector<int> vec);
    std::vector<int> getVector();
    std::vector<int> getVectorG();
    int getM();
    int getChangeCount();
    void insertionSort(int g);
    void shellSort();
};

ShellSort::ShellSort(std::vector<int> vec){
    this->dataSet = vec;
    this->changeCount = 0;
}

int ShellSort::getChangeCount(){
    return this->changeCount;
}

int ShellSort::getM(){
    return this->m;
}

std::vector<int> ShellSort::getVector(){
    return this->dataSet;
}

std::vector<int> ShellSort::getVectorG(){
    return this->vecG;
}

void ShellSort::insertionSort(int g){
    for(int i = g;i < dataSet.size();i++){
        int v = dataSet[i];
        int j = i - g;
        while(j >= 0 && dataSet[j] > v){
            dataSet[j+g] = dataSet[j];
            j = j - g;
            changeCount++;
        }
        dataSet[j + g] = v;
    }
}

void ShellSort::shellSort(){
    
    for(int i = 0;i < 100;i++){
        if(i == 0){
            double d = ((double)dataSet.size() / 2);
            vecG.push_back(ceil(d) + 1);
        }else{
            vecG.push_back((vecG[i - 1] / 2) - 1);
        }
        if(vecG[i] <= 0){
            vecG[i - 1] = 1;
            vecG.pop_back();
            m = i;
            break;
        }
    }

    for(int i = 0;i < m;i++){
        insertionSort(vecG[i]);
    }
}

void showVector(std::vector<int> vec){
    for(int i = 0;i < vec.size();i++){
        std::cout << (i ? " " : "") << vec[i];
    }
    std::cout << std::endl;
}

int main(){
    
    int content;

    std::cin >> content;

    std::vector<int> vec;

    for(int i = 0;i < content;i++){
        int input;
        std::cin >> input;

        vec.push_back(input);
    }

    ShellSort ss = ShellSort(vec);
    ss.shellSort();

    std::cout << ss.getM() << std::endl;
    showVector(ss.getVectorG());
    std::cout << ss.getChangeCount() << std::endl;
    for(int i : ss.getVector()){
        std::cout << i << std::endl;
    }

    return 0;
}