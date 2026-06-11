#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

std::vector<std::pair<char,int>> run_length_encoding(const std::string& s){
    std::vector<std::pair<char,int>> v;
    char c=s[0]; int cnt=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]==c){
            cnt++;
        }else{
            v.push_back(std::make_pair(c,cnt));
            c = s[i]; cnt = 1;
        }
    }
    v.push_back(std::make_pair(c,cnt)); return v;
}

int main(){
    fast_io();

    std::string s; std::cin >> s;
    std::vector<std::pair<char,int>> v = run_length_encoding(s);
    v.push_back(std::make_pair('R',1));

    std::vector<int> r(s.size()*2,0);
    int r_position = v[0].second - 1;
    for(int i=0; i<v.size(); i+=2){
        r[r_position]   = (v[i].second - v[i].second/2) + v[i+1].second/2;
        r[r_position+1] = v[i].second/2 + (v[i+1].second - v[i+1].second/2);

        r_position += v[i+1].second + v[i+2].second;
    }

    for(int i=0; i<s.size(); i++){
        std::cout << r[i] << " ";
    }
    std::cout << "\n";
    return 0;
}
