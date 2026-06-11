#include<bits/stdc++.h>
using P = std::pair<std::string,int>;

int main(){
        int n;
        scanf("%d", &n);

        std::vector<P> st(n);
        for(int i=0; i<n; i++){
                std::cin >> st[i].first >> st[i].second;
        }

        std::string x;
        std::cin >> x;
        int ans = 0;
        bool flag = 0;
        for(int i=0; i<n; i++){
                if(flag) ans += st[i].second;
                if(x==st[i].first) flag = 1;
        }

        printf("%d\n", ans);
        return 0;
}