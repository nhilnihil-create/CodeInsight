#include<iostream>
#include<deque>
using namespace std;


int main(){
    int n, p_single, count = 0;
    deque<int> p;
    std::cin >> n;

    std::cin >> p_single;
    p.push_back(p_single);

    std::cin >> p_single;
    p.push_back(p_single);

    std::cin >> p_single;
    p.push_back(p_single);

    for(int i = 3; i <= n; i++){
        if(p[0] < p[1] && p[1] < p[2]){
            count++;
        }else if(p[0] > p[1] && p[1] > p[2]){
            count++;
        }
        if(i != n){
            std::cin >> p_single;
            p.push_back(p_single);
            p.pop_front();
        }
    }

    std::cout << count;


}