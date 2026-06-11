#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;

    long long s[m], c[m];
    for(long long i = 0; i < m; i++) cin >> s[i] >> c[i];

    for(long long i = 0; i <= 999; i++){
        string t;
        t = to_string(i);
        if(t.size() != n) continue;
       
        bool find = true;
        for(long long j = 0; j < m; j++){
            if(t[s[j]-1] != c[j]+'0') find = false;
        }
        if(find == true){
            printf("%lld\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}