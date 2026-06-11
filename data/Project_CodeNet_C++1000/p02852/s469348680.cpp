/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int n;
int m;
int dist[N];
char str[N];
int parent[N];

int main(){
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        cin >> str[i];
    }
    int me = n;
    while(me != 0){
        int will = -1;
        for(int i = me-1; i >= me - m && i >= 0; i--){
            if(str[i] == '0'){
                will = i;
            }
        }
        if(will == -1){
            puts("-1");
            return 0;
        }
        dist[will] = me - will;
        parent[will] = me;
        me = will;
    }
    int j = 0;
    while(j != n){
        printf("%d " , dist[j]);
        j = parent[j];
    }
}