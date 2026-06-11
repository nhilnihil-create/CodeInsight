#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

#define ll long long
#define rep(i,n) for(int i=0; i<(n); ++i)
#define P std::pair<std::string,int>

bool compare(P x, P y){
    if(x.second == y.second)
        return x.first < y.first;
    return x.second > y.second;
}

int main(){
    int n; std::cin >> n;
    std::map<std::string, int> mp;
    rep(i,n){
        std::string s; std::cin >> s;
        ++mp[s];
    }
    std::vector<P> vec;
    for(auto m : mp)
        vec.push_back(P(m.first,m.second));
    std::sort(vec.begin(),vec.end(),compare);

    int cnt = vec[0].second;
    for(auto v : vec)
        if(cnt == v.second)
            std::cout << v.first << std::endl;

    return 0;
}