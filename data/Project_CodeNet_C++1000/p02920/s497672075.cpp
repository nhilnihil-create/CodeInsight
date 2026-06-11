#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e5+7;

int main(){
    int n;
    scanf("%d", &n);
    int cnt = (1<<n), tp;
    vector<int> p;
    for(int i = 0 ; i < cnt ; i++){
        scanf("%d", &tp);
        p.push_back(tp);
        //printf("%d ", p[i]);
    }
    //puts("");
    sort(p.begin(), p.end());
    queue<int> q;
    vector<int>::iterator it = p.end();
    --it;
    q.push(*it);
    it = p.erase(it);
    while( !p.empty() ){
        int&& ct = q.size();
        while( ct-- ){
            int u = q.front();q.pop();
            it = lower_bound(p.begin(), p.end(), u);
            if( it != p.begin() ){
                --it;
            }else{
                return 0*puts("No");
            }
            q.push(u);
            q.push(*it);
            it = p.erase(it);
        }
    }
    puts("Yes");
    return 0;
}
