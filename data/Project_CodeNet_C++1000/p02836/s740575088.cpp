#include<iostream>
#include<vector>
using namespace std;

int main(){
    string str;
    std::cin >> str;

    int N = str.size();
    int n = (str.size() - str.size()%2)/2;
    int count = 0;

    for(int i = 0; i < n; i++){
        if(str[i] != str[N-1-i]){
            count++;
        }
    }
    std::cout << count; 
}