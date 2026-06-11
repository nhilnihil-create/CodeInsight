#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main(){
    int N;
    scanf("%d", &N);

    multiset<ii> SE;
    multiset<ii> ES;
    for(int i = 0; i < N; i ++){
        int x, l;
        scanf("%d%d", &x, &l);
        SE.insert(ii(x-l, x+l));
        ES.insert(ii(x+l, x-l));
    }

    int ans = 0;
    int lastCovered = -2147483647;
    while(!SE.empty()){
        ii temp = *ES.begin();
        int e = temp.first;
        int s = temp.second;

        //printf("s=%d e=%d\n", s, e);

        ES.erase(ES.find(ii(e, s)));
        SE.erase(SE.find(ii(s, e)));
        if(s >= lastCovered){
            ans ++;
            lastCovered = e;
        }
    }

    printf("%d", ans);
    return 0;
}
