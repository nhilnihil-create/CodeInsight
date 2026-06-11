#include<bits/stdc++.h>
using P = std::pair<int,int>;

int main(){
        int n, m;
        scanf("%d %d", &n, &m);
        char s[n+2];
        scanf("%s", s);

        std::vector<int> ans(0);
        for(int i=n; i>0;){
                for(int j=std::max(0,i-m); j<=i; j++){
                        if(j==i){
                                puts("-1");
                                return 0;
                        }
                        if(s[j]=='0'){
                                ans.push_back(i-j);
                                i = j;
                                break;
                        }
                }
        }

        for(int i=ans.size()-1; i>=0; i--) printf("%d ", ans[i]);
        puts("");
        return 0;
}
