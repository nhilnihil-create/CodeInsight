#include<iostream>
#include<string>
#include<map>
int main(){
        std::map<std::string,int> weekday{
                {"SUN",0},
                {"MON",1},
                {"TUE",2},
                {"WED",3},
                {"THU",4},
                {"FRI",5},
                {"SAT",6}};
        std::string S;
        std::cin >> S;
        std::cout << 7 - weekday[S];
}