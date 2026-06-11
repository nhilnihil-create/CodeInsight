#include <bits/stdc++.h>
using namespace std;
 
int a[(1 << 18) + 5];
 
int main(){
 
    int n; cin >> n;
    int maxi = 0;
    multiset<int> ms;
    for(int i = 0; i < (1 << n); i++){
        cin >> a[i];
        maxi = max(maxi, a[i]);
        ms.insert(a[i]);
    }
    if(ms.count(maxi) > 1){
        puts("No");
        return 0;
    }
    
    multiset<int> ms_cur; ms_cur.insert(maxi);
    for(int i = 0; i < n; i++){
        vector<int> aux;
        for(int x : ms_cur){
            if(ms.empty()){
                puts("No");
                return 0;
            }
            auto it = ms.lower_bound(x);
            if(it == ms.begin()){
                puts("No");
                return 0;
            }
            it--;
            aux.push_back(*it);
            ms.erase(it);
        }
        for(int x : aux)
            ms_cur.insert(x);
    }
    puts("Yes");
    return 0;
}