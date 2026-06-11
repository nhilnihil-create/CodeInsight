#include<iostream>
#include<vector>
#define rep(i,n) for(int i=0; i<(n); ++i)

int main(){
    int n,m; std::cin >> n >> m;
    std::vector<bool> ac(n+1,false);
    std::vector<int> wa_cnt(n+1,0);
    rep(i,m){
        int p;
        std::string s;
        std::cin >> p >> s;
        if(ac[p]) continue;
        if(s == "WA")
            ++wa_cnt[p];
        else
            ac[p] = true;
    }
    int AC=0, WA=0;
    for(int i=1; i<n+1; ++i){
        if(ac[i]){
            ++AC;
            WA += wa_cnt[i];
        }
    }
    std::cout << AC << ' ' << WA << std::endl;
    return 0;
}