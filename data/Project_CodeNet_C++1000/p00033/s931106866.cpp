#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    while(n--){
        vector<int> v(10);
        for(int i=0; i< 10; i++) cin >> v[i];
        int a=0, b=0;
        bool is = true;
        for(int i=0; i< 10; i++){
            if(v[i] < a && v[i] < b){is = false; break;}
            if(a < b) (b<v[i]?b:a) = v[i];
            else (a<v[i]?a:b) = v[i];
        }
        cout << (is?"YES":"NO") << endl;
    }
}