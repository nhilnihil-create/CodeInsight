#include <bits/stdc++.h>

int stoi(std::string);
std::string itos(int);

int main(){
    int sum,digits[200]={0};
    std::string input,output;


    std::ios::sync_with_stdio(false);

    input = "";
    for (int i=0;i<200;i++){
        sum = 0;

        for (int j=0;j<2;j++){
            if((int)std::cin.eof()) goto end;
            std::cin >> input;
            sum += stoi(input);
        }
        output = itos(sum);
        digits[i] = (int)output.length();
    }
    end:
    for (int i=0;digits[i];i++){
        std::cout << digits[i] << std::endl;
    }
}

int stoi(std::string s){
    std::stringstream ss;
    int i;
    ss << s;
    ss >> i;
    return i;
}

std::string itos(int i){
    std::stringstream ss;
    std::string str;
    ss << i;
    ss >> str;
    return str;
}