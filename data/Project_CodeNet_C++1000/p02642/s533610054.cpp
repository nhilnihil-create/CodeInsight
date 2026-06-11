#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int>v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        
        sort(v.begin(), v.end());
        bool check[1000005];
        memset(check, false, sizeof check);
        int cnt = 0;
        
        for(int i = 0; i < n; i++){
            int val = v[i];
            if(i+1 < n && v[i] == v[i+1]){
                check[v[i]] = true;
                continue;
            }
            bool f = true;
            for(int j = 1; j <= sqrt(val); j++){
                if(val%j == 0){
                    int a = j;
                    int b = val / j ;
                    if(check[a] == true || check[b] == true){
                        f = false;
                    }
                }
            }
            if(f){
                cnt++;
            }
            check[val] = true;
        }
        cout << cnt << "\n";
    }
    return 0;
}